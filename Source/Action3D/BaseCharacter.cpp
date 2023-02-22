// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseCharacter.h"
#include "CustomMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "Components/CapsuleComponent.h"

// ������ ��������� ��� �������� ���������
ABaseCharacter::ABaseCharacter(/*const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.SetDefaultSubobjectClass<UCustomMovementComponent>
		(ACharacter::CharacterMovementComponentName)*/)
{	
	UCustomMovementComponent->bIsCrouching = false;
	bIsSprinting = false;
	
	BaseWalkSpeed = 500.f;
	SprintSpeed = 800.f;
	
	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;


	// ����� �� �������� �������������� � ����������� ��������
	GetCharacterMovement()->bOrientRotationToMovement = true; 
	// ������ �������� �������� ��������� �� ���� Y, Z � X
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); 
	// ������ ���� ������
	GetCharacterMovement()->JumpZVelocity = 600.f;
	// ���������� ������������� ��������� � ������/�������
	GetCharacterMovement()->AirControl = 0.2f; 


	// ������� ����� ����� ������
	BaseCameraBoom = CreateDefaultSubobject<USpringArmComponent>("BaseCameraBoom"); 
	// ������ ������ ������ � ��������� ����������
	BaseCameraBoom->SetupAttachment(RootComponent); 
	// ������ ����� �����
	BaseCameraBoom->TargetArmLength = 300.f; 
	
	// ����� �� ��� �������������� � ������� ��������
	BaseCameraBoom->bUsePawnControlRotation = true;

	BaseCamera = CreateDefaultSubobject<UCameraComponent>("BaseFollowCamera");
	BaseCamera->SetupAttachment(BaseCameraBoom, USpringArmComponent::SocketName);
		
	CrouchEyeOffset = FVector(0.f);
	
	// �������� �� �������� ������/�������� ������ �� ��� Z ��� ����������/�������
	CrouchCameraSpeed = 5.f;

}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	float CrouchInterpTime = FMath::Min(1.f, CrouchCameraSpeed * DeltaTime);
	CrouchEyeOffset = ((1.f - CrouchInterpTime) * CrouchEyeOffset);
		
}


//=========================================
//             �������� ������
//=========================================

void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ABaseCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ABaseCharacter::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ABaseCharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ABaseCharacter::StopJumping);

	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &ABaseCharacter::StartSprinting);
	PlayerInputComponent->BindAction("Sprint", IE_Released, this, &ABaseCharacter::StopSprinting);

	 /* ������� ��� �������������: 
			1. StartCrouch � EndCrouch �� ������, ���� �� ����� ���������/�������� �� ��������� ������� 
			2. ToggleCrouch - ���� ����� ������������� ����� �������� ����� ��������
	 */

	//PlayerInputComponent->BindAction("ToggleCrouch", IE_Pressed, this, &ABaseCharacter::StartCrouch);
	//PlayerInputComponent->BindAction("ToggleCrouch", IE_Released, this, &ABaseCharacter::EndCrouch);
    PlayerInputComponent->BindAction("ToggleCrouch", IE_Pressed, this, &ABaseCharacter::ToggleCrouch);
}


//=========================================
//  �������� �����/������, ������/�����
//=========================================

// �������� ������/�����
void ABaseCharacter::MoveForward(float AxisValue)
{
	if ((Controller != nullptr) && (AxisValue != 0.0f))
	{
		FRotator Rotation = Controller->GetControlRotation();
		FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

		FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		AddMovementInput(Direction, AxisValue);
	}
}

// �������� ������/�����
void ABaseCharacter::MoveRight(float AxisValue)
{
	if ((Controller != nullptr) && (AxisValue != 0.0f))
	{
		FRotator Rotation = Controller->GetControlRotation();
		FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

		FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		AddMovementInput(Direction, AxisValue);
	}
}

// ����������� ����� ��������/������ 
void ABaseCharacter::ToggleCrouch()
{
	if (bIsCrouching)
	{	
		bIsCrouching = false;
		UnCrouch();
	}
	else
	{	
		bIsCrouching = true;
		Crouch();
	}
}



//==============================================
//         ������� ������ ��� ����������
//==============================================

void ABaseCharacter::OnStartCrouch(float HalfHeightAdjust, float ScaledHalfHeighAdjust)
{
	if (HalfHeightAdjust == 0.f) { return; }

	// ��������� ������ "����" �� ����������
	float StartBaseEyeHeight = BaseEyeHeight;

	Super::OnStartCrouch(HalfHeightAdjust, ScaledHalfHeighAdjust);

	CrouchEyeOffset.Z += StartBaseEyeHeight - BaseEyeHeight + HalfHeightAdjust;

	// ���������� ��������� ������ ����� ����������
	BaseCamera->SetRelativeLocation(FVector(0.f, 0.f, BaseEyeHeight), false);

}

void ABaseCharacter::OnEndCrouch(float HalfHeightAdjust, float ScaledHalfHeighAdjust)
{
	if (HalfHeightAdjust == 0.f) { return; }

	float StartBaseEyeHeight = BaseEyeHeight;
	Super::OnEndCrouch(HalfHeightAdjust, ScaledHalfHeighAdjust);

	CrouchEyeOffset.Z += StartBaseEyeHeight - BaseEyeHeight - HalfHeightAdjust;
	BaseCamera->SetRelativeLocation(FVector(0.f, 0.f, BaseEyeHeight), false);
}

void ABaseCharacter::CalcCamera(float DeltaTime, struct FMinimalViewInfo& OutResult)
{
	if (BaseCamera)
	{
		BaseCamera->GetCameraView(DeltaTime, OutResult);
		OutResult.Location += CrouchEyeOffset;
	}
}


//==============================================
//					������
//==============================================


void ABaseCharacter::StartSprinting()
{	
	bIsSprinting = true;
	Sprint();
	UE_LOG(LogClass, Warning, TEXT("Sprint!"));
}

void ABaseCharacter::StopSprinting()
{
	bIsSprinting = false;
	StopSprint();
	UE_LOG(LogClass, Warning, TEXT("Stop Sprint!"));
}
