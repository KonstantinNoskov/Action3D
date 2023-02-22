// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"


class UCustomMovementComponent;
class UCameraComponent;
class USpringArmComponent;
class UInputComponent;


UCLASS()
class ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter(/*const FObjectInitializer& ObjectInitializer*/);
	
	// ќбъ€вл€ем необходимые компоненты...

	// ...перемещение персонажа...
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCharacterMovementComponent* BaseMovementComponent;

	// ...камеру персонажа...
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* BaseCamera;

	// ...локоть камеры персонажа...
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* BaseCameraBoom;

	UCustomMovementComponent* CustomMovementComponent;

	UFUNCTION(BlueprintImplementableEvent)
	void Sprint();

	UFUNCTION(BlueprintImplementableEvent)
	void StopSprint();

	UPROPERTY(BlueprintReadOnly, Category = "Movement: Crouch")
	bool bIsCrouching;
	
	//CharacterState GetCurrentState();
		
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	

	// ...прив€зку управлени€ персонажа.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UInputComponent* BaseInputComponent;

	UPROPERTY(BlueprintReadWrite, Category = Crouch)
	FVector CrouchEyeOffset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Crouch)
	float CrouchCameraSpeed;

	UPROPERTY(BlueprintReadOnly, Category = Sprint)
	bool bIsSprinting;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Sprint)
	float SprintSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Sprint)
	float BaseWalkSpeed;
					
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	
	void StartSprinting();
	void StopSprinting();

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void ToggleCrouch();
	void OnStartCrouch(float HalfHeightAdjust, float ScaledHalfHeighAdjust) override;
	void OnEndCrouch(float HalfHeightAdjust, float ScaledHalfHeighAdjust) override;

	// ƒвижение вперед/назад
	void MoveForward(float AxisValue);

	// ƒвижение вправо/влево
	void MoveRight(float AxisValue);

	void CalcCamera(float DeltaTime, struct FMinimalViewInfo& OutResult) override;
};
