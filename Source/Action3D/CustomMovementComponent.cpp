// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomMovementComponent.h"


//=========================================
//             Приседания
//=========================================

UCustomMovementComponent::UCustomMovementComponent()
{
	bIsCrouching = false;
}



// Тупо вызывает родительскую функцию, чтобы присесть...
void UCustomMovementComponent::StartCrouch()
{
	bIsCrouching = true;
	Crouch();
}

// ... и чтобы встать.
void UCustomMovementComponent::EndCrouch()
{
	bIsCrouching = false;
	UnCrouch();
}