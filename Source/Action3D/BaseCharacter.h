// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

UCLASS()
class ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

	// �������� ������/�����
	void MoveForward(float AxisValue);

	// �������� ������/�����
	void MoveRight(float AxisValue);

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
		
	void OnStartCrouch(float HalfHeightAdjust, float ScaledHalfHeighAdjust) override;
	void OnEndCrouch(float HalfHeightAdjust, float ScaledHalfHeighAdjust) override;

	void CalcCamera(float DeltaTime, struct FMinimalViewInfo& OutResult) override;
	
	void ToggleCrouch();
	void StartCrouch();
	void EndCrouch();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// ��������� ����������� ����������...

	// ...����������� ���������...
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCharacterMovementComponent* BaseMovementComponent;

	// ...������ ���������...
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* BaseCamera;

	// ...������ ������ ���������...
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* BaseCameraBoom;

	// ...�������� ���������� ���������.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UInputComponent* BaseInputComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Crouch)
		bool bIsCrouching;

	UPROPERTY(BlueprintReadWrite, Category = Crouch)
		FVector CrouchEyeOffset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Crouch)
		float CrouchCameraSpeed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Sprint)
		bool bIsSprint;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Sprint)
		float SprintSpeed;
	
		
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
