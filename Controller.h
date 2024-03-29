/////////////////////
// Controller.h
/////////////////////

#pragma once
#include <Windows.h>
#include "Shader.h"
#include "Model.h"
#include "Laser.h"

// Std includes
#include <stdio.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <memory>
#include <vector>

// GLM includes
#include <glm/glm.hpp>
#include <glm/gtc/noise.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <GL/glew.h>

#include <OVR_CAPI.h>
#include <OVR_CAPI_GL.h>

struct Ray {
	glm::vec3 origin;
	glm::vec3 dir;
	float dist;
};

class Controller {
public:
	glm::vec3 position;
	glm::vec4 rotation;
	glm::vec3 scale;

	//// 
	glm::mat4 model;
	// Controlls for this controller
	ovrInputState inputState;
	ovrTouch btn1, btn2;
	ovrHandType hand;

	Controller(std::shared_ptr<Model> & model);
	void loadS(); 
	void Render(glm::mat4 view, glm::mat4 proj);

	glm::vec3 GetColor();

	Ray ray;
private:
	/* Data */
	Laser laser;
	std::shared_ptr<Model> controllerModel;
	GLchar* vertexShaderPath = "./controllerShader.vert";
	GLchar* fragShaderPath   = "./controllerShader.frag";
	GLint controllerShader;


	/* Functions */
	glm::mat4 GetModelMatrix();
};