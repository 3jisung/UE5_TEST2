// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "SnakePawn.generated.h"

UCLASS()
class TEST0614_API ASnakePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ASnakePawn();

	UFUNCTION(BlueprintCallable)
		FORCEINLINE void SetHead(AActor* _Head)
	{
		Head = _Head;
	}

	UFUNCTION(BlueprintCallable)
		void HeadPositionToCenter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	// 이녀석을 아예 블루프린트에서 쓸수있게 만드는 방법.
	AActor* Head;
};
