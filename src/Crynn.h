/// Includes almost all necessary engine components.
#pragma once
#define IMGUI_DEFINE_MATH_OPERATORS

#include "Core/Window.h"
#include "Core/Camera.h"
#include "Core/Input.h"
#include "Core/MeshRenderer.h"
#include "Core/Shader.h"
#include "Core/EventListener.h"
#include "Core/Application.h"
#include "Core/Transform.h"
#include "Core/Mesh.h"
#include "Core/CrynnObject.h"

#include "Core/Collision/AABB.h"

#include "Utility/Debug.h"
#include "Utility/File.h"
#include "Utility/Timer.h"
#include "Utility/Random.h"

#include "GUI/GuiWindow.h"
#include "GUI/MatrixEditor.h"

#include "imgui.h"
#include "imgui_internal.h"

#include <memory>
#include <future>
#include <mutex>

#define DATA_PATH "data/"
#define CRYNN_EVENT static inline Event<void>

using namespace glm;