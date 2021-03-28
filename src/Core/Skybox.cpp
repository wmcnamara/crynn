#include "Skybox.h"

namespace crynn
{
    Skybox::Skybox(const SkyboxFilePathData& sbData) : 
        m_shader(sbData.skyShader), 
        Mesh(skyboxVertices, skyboxVerticesSize, 0, 0, VertexAttribNone)
    {
        glGenTextures(1, &m_id);
        glBindTexture(GL_TEXTURE_CUBE_MAP, m_id);

        int width, height, nrChannels;
        unsigned char* data;
        for (unsigned int i = 0; i < 6; i++)
        {
            stbi_set_flip_vertically_on_load(false);
            data = stbi_load(sbData.filepaths[i], &width, &height, &nrChannels, 0);
            glTexImage2D(
                GL_TEXTURE_CUBE_MAP_POSITIVE_X + i,
                0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data
            );

            stbi_image_free(data);
        }

        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
    }

    Skybox::~Skybox()
    {
        glDeleteTextures(1, &m_id);
    }
    
    void Skybox::BeforeUpdate(double dt)
    {
        glDepthMask(GL_FALSE);

        m_shader.Use();
        GetVAO().Bind();

        glBindTexture(GL_TEXTURE_CUBE_MAP, m_id);
        glDrawArrays(GL_TRIANGLES, 0, 36);
        glDepthMask(GL_TRUE);
    }
}