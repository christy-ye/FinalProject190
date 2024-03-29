/////////////////////
// Laser.h
/////////////////////

#pragma once
#include <Windows.h>
#include "Shader.h"
#include "Model.h"

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

class Laser {
public:
	float laserDist = 75.0f;;
	glm::vec3 position;
	glm::vec4 rotation;
	glm::vec3 scale;

	Laser();
	void Render(glm::mat4 view, glm::mat4 proj);
	void Draw();
	void SetGreen();
	void SetRed();
	glm::vec3 color;

private:
	/* Data */
	std::vector<GLfloat> vertices;
	std::vector<GLuint> indices;

	GLchar* vertexShaderPath = "H:/FinalProject/MinimalVR-master/Minimal/lineShader.vert";
	GLchar* fragShaderPath   = "H:/FinalProject/MinimalVR-master/Minimal/lineShader.frag";
	GLint laserShader;
	GLuint VAO, VBO, EBO;
};