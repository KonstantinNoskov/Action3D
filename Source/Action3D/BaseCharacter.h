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

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
		
	// ƒвижение вперед/назад
	void MoveForward(float AxisValue);

	// ƒвижение вправо/влево
	void MoveRight(float AxisValue);
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	// ќбъ€вл€ем необходимые компоненты...

	// ...перемещение персонажа...
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCharacterMovementComponent* BaseMovementComponent;

	// ...камеру персонажа...
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* BaseCameraComponent;
	
	// ...локоть камеры персонажа...
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* BaseSpringArmComponent;

	// ...прив€зку управлени€ персонажа.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UInputComponent* BaseInputComponent;

private:
	/*UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "BaseBody", meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* BaseBodyMesh;*/
};
