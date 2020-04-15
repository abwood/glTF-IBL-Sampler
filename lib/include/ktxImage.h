#pragma once

#include <vector>
#include <vulkan/vulkan.h>
#include "slimktx2.h"
#include "ResultType.h"

namespace IBLLib
{
	class KtxImage
	{
	public:

		KtxImage();			
		KtxImage(uint32_t _width, uint32_t _height, VkFormat _vkFormat, uint32_t _levels, bool _isCubeMap);
		~KtxImage();

		IBLLib::Result loadKtx2(const char* _pFilePath);

		Result writeFace(const std::vector<uint8_t>& _inData, uint32_t _side, uint32_t _level);
		Result save(const char* _pathOut);

		uint32_t getWidth() const { return m_slimKTX2.getHeader().pixelWidth; }
		uint32_t getHeight() const { return m_slimKTX2.getHeader().pixelHeight; }
		uint32_t getLevels() const { return m_slimKTX2.getHeader().levelCount; }
		bool isCubeMap() const { return m_slimKTX2.getHeader().faceCount == 6u; }
		VkFormat getFormat() const { return static_cast<VkFormat>(m_slimKTX2.getHeader().vkFormat); }

	private:
		ux3d::slimktx2::SlimKTX2 m_slimKTX2;
	};

} // !IBLLIb
