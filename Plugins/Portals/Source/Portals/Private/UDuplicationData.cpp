// Fill out your copyright notice in the Description page of Project Settings.


#include "UDuplicationData.h"

UDuplicationData::UDuplicationData()
{
}

UDuplicationData::~UDuplicationData()
{
}


UDuplicationData::UDuplicationData(AActor* Portal, AActor* Object)
	: Portal(Portal), Object(Object)
{
}

UDuplicationData* UDuplicationData::MakeDuplicationData(AActor* newPortal, AActor* newObject)
{
	UDuplicationData* Data = NewObject<UDuplicationData>();
	Data->Portal = newPortal;
	Data->Object = newObject;
	return Data;
}

void UDuplicationData::Destroy()
{
	this->ConditionalBeginDestroy();
}
