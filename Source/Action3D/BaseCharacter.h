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

	//virtual FVector GetPawnViewLocation() const override;
	//virtual UCapsuleComponent* GetCapsuleComponent() const override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
		
	// Движение вперед/назад
	void MoveForward(float AxisValue);

	// Движение вправо/влево
	void MoveRight(float AxisValue);
		
	virtual void Crouch(bool bClientSimulation = false) override;
	virtual void UnCrouch(bool bClientSimulation = false) override;
		
	/*UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Crouch)
	bool bCanCrouch;*/

	class UCapsuleComponent* BaseCapsule;
			
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	

	// Объявляем необходимые компоненты...

	// ...перемещение персонажа...
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCharacterMovementComponent* BaseMovementComponent;

	// ...камеру персонажа...
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* BaseCameraComponent;
	
	// ...локоть камеры персонажа...
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* BaseSpringArmComponent;

	// ...привязку управления персонажа.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UInputComponent* BaseInputComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Crouch")
	bool bIsCrouching;

private:
	/*UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "BaseBody", meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* BaseBodyMesh;*/

	// Переключает между стойкой и приседом. 
	void ToggleCrouch();

	// Именяет размер колизии
	void AdjustCapsuleSize(bool bCrouch);
};
