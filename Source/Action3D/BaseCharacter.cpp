// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "Components/CapsuleComponent.h"

// Задаем параметры для базового персонажа
ABaseCharacter::ABaseCharacter()
{

	bIsCrouching = false;
	/*bCanCrouch = true;*/


	BaseCapsule = CreateDefaultSubobject<UCapsuleComponent>("BaseCapsule");
		
	/*BaseBodyMesh = CreateDefaultSubobject<USkeletalMeshComponent>("BaseBodyMesh");
	RootComponent = BaseBodyMesh;*/

	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Будет ли персонаж поворачиваться в направлении взгляда
	GetCharacterMovement()->bOrientRotationToMovement = true; 
	// Задает скорость поворота персонажа по осям Y, Z и X
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); 
	// Задает силу прыжка
	GetCharacterMovement()->JumpZVelocity = 600.f;
	// Коэффицент управляемости персонажа в прыжке/падении
	GetCharacterMovement()->AirControl = 0.2f; 


	// Создаем копию локтя камеры
	BaseSpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("BaseCameraBoom"); 
	// Крепим локоть камеры к корневому компоненту
	BaseSpringArmComponent->SetupAttachment(RootComponent); 
	// Задаем длину локтя
	BaseSpringArmComponent->TargetArmLength = 300.f; 
	//
	BaseSpringArmComponent->bUsePawnControlRotation = true;

	BaseCameraComponent = CreateDefaultSubobject<UCameraComponent>("BaseFollowCamera");
	BaseCameraComponent->SetupAttachment(BaseSpringArmComponent, USpringArmComponent::SocketName);
	BaseCameraComponent->bUsePawnControlRotation = false;

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
}

////////////////////////////////////
///  Binding Control Keys
////////////////////////////////////

void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ABaseCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ABaseCharacter::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ABaseCharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ABaseCharacter::StopJumping);

	PlayerInputComponent->BindAction("ToggleCrouch", IE_Pressed, this, &ABaseCharacter::ToggleCrouch);
	/*PlayerInputComponent->BindAction("ToggleCrouch", IE_Pressed, this, &ABaseCharacter::Crouch);
	PlayerInputComponent->BindAction("ToggleCrouch", IE_Released, this, &ABaseCharacter::UnCrouch);*/
}


/////////////////////////////////////
///  Имлементация движения персонажа
/////////////////////////////////////


// Движение вперед/назад
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

// Движение вправо/влево
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

void ABaseCharacter::ToggleCrouch()
{
	if (bIsCrouching)
	{
		UnCrouch();
	}

	else
	{
		Crouch();
	}
}

void ABaseCharacter::Crouch(bool bClientSimulation)
{
	bIsCrouching = true;
	
	Super::Crouch();
	AdjustCapsuleSize(true);

	UE_LOG(LogClass, Warning, TEXT("Is Crouching!"));
}

void ABaseCharacter::UnCrouch(bool bClientSimulation)
{
	bIsCrouching = false;

	Super::UnCrouch();
	AdjustCapsuleSize(false);

	UE_LOG(LogClass, Warning, TEXT("Is Up!"));
}


void ABaseCharacter::AdjustCapsuleSize(bool bCrouch)
{

	if (!BaseCapsule) return;

	FVector CurrentLocation, CurrentScale;
	FRotator CurrentRotation;

	//BaseCapsule->GetAllComponentScale(CurrentLocation, CurrentRotation, CurrentScale);
	

	if (bCrouch)
	{
		BaseCapsule->SetCapsuleHalfHeight(70.f);
		BaseCapsule->SetRelativeLocation(FVector(0.f, 0.f, 70.f));
	}
	else
	{
		BaseCapsule->SetCapsuleHalfHeight(96.f);
		BaseCapsule->SetRelativeLocation(FVector(0.f, 0.f, 96.f));
	}
}

