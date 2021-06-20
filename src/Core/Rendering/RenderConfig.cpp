#include "RenderConfig.h"
#include "glad/glad.h"

void RenderConfig::EnableDepthTest()
{
	glEnable(GL_DEPTH_TEST);
}

void RenderConfig::DisableDepthTest()
{
	glDisable(GL_DEPTH_TEST);
}