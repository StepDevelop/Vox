// ******************************************************************************
// Filename:    FrontendPage.h
// Project:     Vox
// Author:      Steven Ball
//
// Purpose:
//
// Revision History:
//   Initial Revision - 12/10/14
//
// Copyright (c) 2005-2011, Steven Ball
// ******************************************************************************

#pragma once

#include <string>
using namespace std;

#include <glm/vec3.hpp>
using namespace glm;

#include "FrontendScreens.h"
#include "../gui/label.h"

class Renderer;
class OpenGLGUI;
class FrontendManager;


class FrontendPage
{
public:
	/* Public methods */
	FrontendPage(Renderer* pRenderer, OpenGLGUI* pGUI, FrontendManager* pFrontendManager, eFrontendScreen pageType, int windowWidth, int windowHeight);
	virtual ~FrontendPage();

	virtual void SetWindowDimensions(int width, int height);

	eFrontendScreen GetPageType();

	void SetTitleAndSubtitle(string title, string subtitle);
	void RemoveTitlesAndSubTitle();

	virtual void Reset() = 0;

	virtual void SkinGUI() = 0;
	virtual void UnSkinGUI() = 0;

	virtual void Load() = 0;
	virtual void Unload() = 0;

	vec3 GetCameraPosition();
	vec3 GetCameraView();

	virtual void Update(float dt);

	virtual void Render();
	virtual void Render2D();
	virtual void RenderDebug();

protected:
	/* Protected methods */

private:
	/* Private methods */

public:
	/* Public members */

protected:
	/* Protected members */
	Renderer* m_pRenderer;
	OpenGLGUI* m_pGUI;
	FrontendManager* m_pFrontendManager;

	// Window params
	int m_windowWidth;
	int m_windowHeight;

	// Camera params
	vec3 m_cameraPosition;
	vec3 m_cameraView;

private:
	/* Private members */
	eFrontendScreen m_pageType;

	Label* m_pPageTitle;
	Label* m_pPageSubtitle;
	bool m_addedTitles;
	bool m_updateTitleTextCenterLocation;
};
