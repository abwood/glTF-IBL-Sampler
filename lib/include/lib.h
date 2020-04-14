#pragma once
#include "ResultType.h"

namespace IBLLib
{
	enum OutputFormat
	{
		R8G8B8A8_UNORM = 37,
		R16G16B16A16_SFLOAT = 97,
		R32G32B32A32_SFLOAT = 109
	};

	enum class Distribution : unsigned int 
	{
		None = 0,		// No prefiltering, using this option will simply output the input panorama as a ktx2 cubemap
		Lambertian = 1,	// Generates a prefiltered environment map for diffuse IBL lighting
		GGX = 2,		// Generate a prefiltered environment map for specular IBL lighting
		Charlie = 3		// Generates a prefiltered environment map for sheen IBL lighting
	};

	Result sample(const char* _inputPath, const char* _outputPathCubeMap, const char* _outputPathLUT, Distribution _distribution, unsigned int  _cubemapResolution, unsigned int _mipmapCount, unsigned int _sampleCount, OutputFormat _targetFormat, float _lodBias, bool _inputIsCubeMap, bool _debugOutput);
} // !IBLLib