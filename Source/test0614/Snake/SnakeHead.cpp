// Fill out your copyright notice in the Description page of Project Settings.


#include "SnakeHead.h"
#include "SnakeGameMode.h"

void ASnakeHead::LeftMove(float _Value)
{
	if (0 == _Value)
	{
		return;
	}

	AddActorLocalOffset(FVector::LeftVector);
}


void ASnakeHead::RightMove(float _Value)
{
	if (0 == _Value)
	{
		return;
	}

	AddActorLocalOffset(FVector::RightVector);
}
void ASnakeHead::UpMove(float _Value)
{
	if (0 == _Value)
	{
		return;
	}
	AddActorLocalOffset(FVector::UpVector);
}
void ASnakeHead::DownMove(float _Value)
{
	if (0 == _Value)
	{
		return;
	}
	AddActorLocalOffset(FVector::DownVector);
}

void ASnakeHead::LeftAction()
{
	FVector MovePos = FVector::LeftVector * 100.0f;

	if (true == GetSnakeGameMode()->IsPart(GetActorLocation() + MovePos, "Wall"))
	{
		return;
	}

	AddActorLocalOffset(FVector::LeftVector * 100.0f);

	// 여기에 Body가 있는지 확인해야 한다.
	if (true == GetSnakeGameMode()->IsPart(GetActorLocation(), "Body"))
	{
		AActor* Body = GetSnakeGameMode()->GetPart(GetActorLocation(), "Body");
		Body->Destroy();
		GetSnakeGameMode()->CurBodyReset();
	}

}
void ASnakeHead::RightAction()
{
	FVector MovePos = FVector::RightVector * 100.0f;

	if (true == GetSnakeGameMode()->IsPart(GetActorLocation() + MovePos, "Wall"))
	{
		return;
	}

	AddActorLocalOffset(FVector::RightVector * 100.0f);

	// 여기에 Body가 있는지 확인해야 한다.
	if (true == GetSnakeGameMode()->IsPart(GetActorLocation(), "Body"))
	{
		AActor* Body = GetSnakeGameMode()->GetPart(GetActorLocation(), "Body");
		Body->Destroy();
		GetSnakeGameMode()->CurBodyReset();
	}

}
void ASnakeHead::UpAction()
{
	FVector MovePos = FVector::UpVector * 100.0f;

	if (true == GetSnakeGameMode()->IsPart(GetActorLocation() + MovePos, "Wall"))
	{
		return;
	}


	AddActorLocalOffset(FVector::UpVector * 100.0f);

	// 여기에 Body가 있는지 확인해야 한다.
	if (true == GetSnakeGameMode()->IsPart(GetActorLocation(), "Body"))
	{
		AActor* Body = GetSnakeGameMode()->GetPart(GetActorLocation(), "Body");
		Body->Destroy();
		GetSnakeGameMode()->CurBodyReset();
	}
}
void ASnakeHead::DownAction()
{
	FVector MovePos = FVector::DownVector * 100.0f;

	if (true == GetSnakeGameMode()->IsPart(GetActorLocation() + MovePos, "Wall"))
	{
		return;
	}

	// 이동을 하고 나서
	AddActorLocalOffset(FVector::DownVector * 100.0f);

	// 여기에 Body가 있는지 확인해야 한다.
	if (true == GetSnakeGameMode()->IsPart(GetActorLocation(), "Body"))
	{
		AActor* Body = GetSnakeGameMode()->GetPart(GetActorLocation(), "Body");
		Body->Destroy();
		GetSnakeGameMode()->CurBodyReset();
	}
}