// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "CustomMovementComponent.generated.h"



/**
 * 
 */
UCLASS()
class ACTION3D_API UCustomMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()
	
public:

	UCustomMovementComponent();

	// Crouch
	UPROPERTY(BlueprintReadOnly, Category = "Movement: Crouch")
	bool bIsCrouching;
	UFUNCTION(BlueprintCallable, Category = "Movement: Crouch")
	void StartCrouch();
	UFUNCTION(BlueprintCallable, Category = "Movement: Crouch")
	void EndCrouch();

};

//UENUM(BlueprintType)
//enum class ESprint : uint8
//{
//	MOVE_SprintStart UMETA(Displayname = "Sprint start"),
//	MOVE_SprintEnd UMETA(Displayname = "Srpint ends"),
//	MOVE_MAX UMETA(Hidden)
//};