// Fill out your copyright notice in the Description page of Project Settings.


#include "PortalsFunctionLibrary.h"

bool UPortalsFunctionLibrary::IsInFrustum(AActor* Actor, const UObject* WorldContextObject)
{
	ULocalPlayer* LocalPlayer = WorldContextObject->GetWorld()->GetFirstLocalPlayerFromController();
	if (LocalPlayer != nullptr && LocalPlayer->ViewportClient != nullptr && LocalPlayer->ViewportClient->Viewport)
	{
		FSceneViewFamilyContext ViewFamily(FSceneViewFamily::ConstructionValues(
			LocalPlayer->ViewportClient->Viewport,
			WorldContextObject->GetWorld()->Scene,
			LocalPlayer->ViewportClient->EngineShowFlags)
			.SetRealtimeUpdate(true));

		FVector ViewLocation;
		FRotator ViewRotation;
		FSceneView* SceneView = LocalPlayer->CalcSceneView(&ViewFamily, ViewLocation, ViewRotation, LocalPlayer->ViewportClient->Viewport);
		if (SceneView != nullptr)
		{
			return SceneView->ViewFrustum.IntersectSphere(
				Actor->GetActorLocation(), Actor->GetSimpleCollisionRadius());
		}
	}

	return false;
}
bool UPortalsFunctionLibrary::IsInFrustumComp(USceneComponent* Component, const UObject* WorldContextObject)
{
	ULocalPlayer* LocalPlayer = WorldContextObject->GetWorld()->GetFirstLocalPlayerFromController();
	if (LocalPlayer != nullptr && LocalPlayer->ViewportClient != nullptr && LocalPlayer->ViewportClient->Viewport)
	{
		FSceneViewFamilyContext ViewFamily(FSceneViewFamily::ConstructionValues(
			LocalPlayer->ViewportClient->Viewport,
			WorldContextObject->GetWorld()->Scene,
			LocalPlayer->ViewportClient->EngineShowFlags)
			.SetRealtimeUpdate(true));

		FVector ViewLocation;
		FRotator ViewRotation;
		FSceneView* SceneView = LocalPlayer->CalcSceneView(&ViewFamily, ViewLocation, ViewRotation, LocalPlayer->ViewportClient->Viewport);
		if (SceneView != nullptr)
		{
			return SceneView->ViewFrustum.IntersectBox(
				Component->GetComponentLocation(), Component->Bounds.BoxExtent);
		}
	}

	return false;
}
