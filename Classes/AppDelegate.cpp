#include "AppDelegate.h"
#include "MainMenuScene.h"
#include "SimpleAudioEngine.h"


USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void AppDelegate::initGLContextAttrs()
{
    //set OpenGL context attributions,now can only set six attributions:
    //red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLViewImpl::create("Learning Cocos2d-x Game Developement v3.3");

		glview->setFrameSize(800,480);//change window resolution
        
		director->setOpenGLView(glview);		
    }

	CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("bgMusic.wav");
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("bgMusic.wav",true);

	CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("enemyKill.wav");
	CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("fireRocket.wav");
	CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("gunshot.wav");
	CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("playerKill.wav");
	CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("pop.wav");
	CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("rocketExplode.wav");

    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);

    // create a scene. it's an autorelease object
	auto scene = MainMenu::scene();

    // run
    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}