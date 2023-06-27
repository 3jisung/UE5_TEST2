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
	SetPrevPos(GetActorLocation());
	FVector MovePos = FVector::LeftVector * 100.0f;

	if (true == GetSnakeGameMode()->IsPart(GetActorLocation() + MovePos, "Wall"))
	{
		return;
	}

	if (FVector::ZeroVector == FVector::LeftVector + currentDir)
	{
		return;
	}

	if (true == GetSnakeGameMode()->IsPart(GetActorLocation() + MovePos, "Body"))
	{
		UE_LOG(LogTemp, Error, TEXT("Body Trigger. Game Over"));
		return;
	}

	AddActorLocalOffset(FVector::LeftVector * 100.0f);
	currentDir = FVector::LeftVector;
	MoveParts();

	// 여기에 Body가 있는지 확인해야 한다.
	if (true == GetSnakeGameMode()->IsPart(GetActorLocation(), "BodyItem"))
	{
		AActor* BodyItem = GetSnakeGameMode()->GetPart(GetActorLocation(), "BodyItem");
		GetSnakeGameMode()->AddBody(this);
		
		BodyItem->Destroy();
		GetSnakeGameMode()->CurBodyReset();
	}

}

void ASnakeHead::RightAction()
{
	SetPrevPos(GetActorLocation());
	FVector MovePos = FVector::RightVector * 100.0f;

	if (true == GetSnakeGameMode()->IsPart(GetActorLocation() + MovePos, "Wall"))
	{
		return;
	}

	if (FVector::ZeroVector == FVector::RightVector + currentDir)
	{
		return;
	}

	if (true == GetSnakeGameMode()->IsPart(GetActorLocation() + MovePos, "Body"))
	{
		UE_LOG(LogTemp, Error, TEXT("Body Trigger. Game Over"));
		return;
	}

	AddActorLocalOffset(FVector::RightVector * 100.0f);
	currentDir = FVector::RightVector;
	MoveParts();

	// 여기에 Body가 있는지 확인해야 한다.
	if (true == GetSnakeGameMode()->IsPart(GetActorLocation(), "BodyItem"))
	{
		AActor* BodyItem = GetSnakeGameMode()->GetPart(GetActorLocation(), "BodyItem");
		GetSnakeGameMode()->AddBody(this);

		BodyItem->Destroy();
		GetSnakeGameMode()->CurBodyReset();
	}

}

void ASnakeHead::UpAction()
{
	SetPrevPos(GetActorLocation());
	FVector MovePos = FVector::UpVector * 100.0f;

	if (true == GetSnakeGameMode()->IsPart(GetActorLocation() + MovePos, "Wall"))
	{
		return;
	}

	if (FVector::ZeroVector == FVector::UpVector + currentDir)
	{
		return;
	}

	if (true == GetSnakeGameMode()->IsPart(GetActorLocation() + MovePos, "Body"))
	{
		UE_LOG(LogTemp, Error, TEXT("Body Trigger. Game Over"));
		return;
	}

	AddActorLocalOffset(FVector::UpVector * 100.0f);
	currentDir = FVector::UpVector;
	MoveParts();

	// 여기에 Body가 있는지 확인해야 한다.
	if (true == GetSnakeGameMode()->IsPart(GetActorLocation(), "BodyItem"))
	{
		AActor* BodyItem = GetSnakeGameMode()->GetPart(GetActorLocation(), "BodyItem");
		GetSnakeGameMode()->AddBody(this);

		BodyItem->Destroy();
		GetSnakeGameMode()->CurBodyReset();
	}
}

void ASnakeHead::DownAction()
{
	SetPrevPos(GetActorLocation());
	FVector MovePos = FVector::DownVector * 100.0f;

	if (true == GetSnakeGameMode()->IsPart(GetActorLocation() + MovePos, "Wall"))
	{
		return;
	}

	if (FVector::ZeroVector == FVector::DownVector + currentDir)
	{
		return;
	}

	if (true == GetSnakeGameMode()->IsPart(GetActorLocation() + MovePos, "Body"))
	{
		UE_LOG(LogTemp, Error, TEXT("Body Trigger. Game Over"));
		return;
	}

	// 이동을 하고 나서
	AddActorLocalOffset(FVector::DownVector * 100.0f);
	currentDir = FVector::DownVector;
	MoveParts();

	// 여기에 Body가 있는지 확인해야 한다.
	if (true == GetSnakeGameMode()->IsPart(GetActorLocation(), "BodyItem"))
	{
		AActor* BodyItem = GetSnakeGameMode()->GetPart(GetActorLocation(), "BodyItem");
		GetSnakeGameMode()->AddBody(this);

		BodyItem->Destroy();
		GetSnakeGameMode()->CurBodyReset();
	}
}

void ASnakeHead::MoveParts()
{
	ASnakePart* currentPart = this;

	while (currentPart->GetNext() != nullptr)
	{
		currentPart = currentPart->GetNext();

		currentPart->SetPrevPos(currentPart->GetActorLocation());
		currentPart->SetActorLocation(currentPart->GetPrev()->GetPrevPos());
	}
}