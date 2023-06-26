// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SnakePart.h"
#include "SnakeHead.generated.h"

/**
 * 
 */
UCLASS()
class TEST0614_API ASnakeHead : public ASnakePart
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
		void LeftMove(float _Value);

	UFUNCTION(BlueprintCallable)
		void RightMove(float _Value);

	UFUNCTION(BlueprintCallable)
		void UpMove(float _Value);

	UFUNCTION(BlueprintCallable)
		void DownMove(float _Value);

	UFUNCTION(BlueprintCallable)
		void LeftAction();

	UFUNCTION(BlueprintCallable)
		void RightAction();

	UFUNCTION(BlueprintCallable)
		void UpAction();

	UFUNCTION(BlueprintCallable)
		void DownAction();
};
