// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SnakePart.generated.h"

UCLASS()
class TEST0614_API ASnakePart : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASnakePart();

	class ASnakeGameMode* GetSnakeGameMode();

	void SetNext(ASnakePart* nextValue);
	void SetPrev(ASnakePart* prevValue);
	void SetPrevPos(FVector prevPosValue);

	ASnakePart* GetNext();
	ASnakePart* GetPrev();
	FVector GetPrevPos();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	ASnakePart* next = nullptr;
	ASnakePart* prev = nullptr;
	FVector prevPos;
};
