#include <cstring>
#include "IRenderer.h"

#include <cstdlib>

IRenderer* MakeEyeRayShooterRenderer(const char* a_name);
IRenderer* MakeRTAORenderer();

IRenderer* CreateRender(const char* a_name)
{
  if (strcmp(a_name, "RTAO") == 0 || strcmp(a_name, "rtao") == 0 || strcmp(a_name, "AO") == 0 || strcmp(a_name, "ao") == 0)
    return MakeRTAORenderer();
  else
    return MakeEyeRayShooterRenderer(a_name);
}

void DeleteRender(IRenderer* pImpl) { delete pImpl; }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

inline float rnd(float s, float e)
{
  const float t = (float)(std::rand()) / (float)RAND_MAX;
  return s + t*(e - s);
}

using LiteMath::float2;
using LiteMath::float4;
using LiteMath::float4x4;

using LiteMath::to_float3;
using LiteMath::translate4x4;
using LiteMath::rotate4x4X;
using LiteMath::rotate4x4Y;
using LiteMath::DEG_TO_RAD;


