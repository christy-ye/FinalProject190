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

#include "LEAP_SDK\include\Leap.h"
using namespace Leap;

struct Ray {
	glm::vec3 origin;
	glm::vec3 dir;
	float dist;
};

class GameController {
public:
	glm::vec3 position;
	glm::vec4 rotation;
	glm::vec3 scale;

	GameController();
	void loadS(); 
	void Render(glm::mat4 view, glm::mat4 proj);

	glm::vec3 GetColor();

	Ray ray;

	Controller control;
	Frame frame; 
	HandList hands;
	Hand firsthand;
	Hand leftmost;
	Hand rightmost; 

private:
	/* Data */
	//Laser laser;
	Model controllerModel;
	GLchar* pathToController = "H:/FinalProject/MinimalVR-master/objects/cube.obj";
	GLchar* vertexShaderPath = "H:/FinalProject/MinimalVR-master/Minimal/shader_1.vert";
	GLchar* fragShaderPath   = "H:/FinalProject/MinimalVR-master/Minimal/shader_1.frag";
	GLint controllerShader;


	/* Functions */
	glm::mat4 GetModelMatrix();
};