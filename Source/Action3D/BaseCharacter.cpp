// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"

// Задаем параметры для базового персонажа
ABaseCharacter::ABaseCharacter()
{

	/*BaseBodyMesh = CreateDefaultSubobject<USkeletalMeshComponent>("BaseBodyMesh");
	RootComponent = BaseBodyMesh;*/

	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true; // Будет ли персонаж поворачиваться в направлении взгляда
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // задает скорость поворота персонажа по осям Y, Z и X
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f; // Коэффицент управляемости персонажа в прыжке/падении


	// Создаем копию локтя камеры
	BaseSpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("BaseCameraBoom");
	// Крепим локоть камеры к корневому компоненту
	BaseSpringArmComponent->SetupAttachment(RootComponent);
	// Задаем длину локтя
	BaseSpringArmComponent->TargetArmLength = 300.f;
	
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
}


/////////////////////////////////////
///  Base Controller Implementation
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