#include "AppDelegate.h"
#include "GameScene.h"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto eglView = EGLView::getInstance();

    director->setOpenGLView(eglView);
	eglView->setDesignResolutionSize(480*0.8, 800*0.8, ResolutionPolicy::EXACT_FIT);
    
    // set resource load resolution
    setResourceSearchResolution();
	
    // turn on display FPS
	director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);

    // create a scene. it's an autorelease object
    // auto scene = HelloWorld::createScene();
	GameScene *scene = GameScene::create();

    // run
    director->runWithScene(scene);

    return true;
}

void AppDelegate::setResourceSearchResolution()
{
    std::vector<std::string> paths;
    paths.push_back("ui");
    paths.push_back("ui/shoot");
    paths.push_back("ui/shoot_background");
    paths.push_back("font");
    paths.push_back("fonts");
    paths.push_back("sound");
    FileUtils::getInstance()->setSearchResolutionsOrder(paths);
}


// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
