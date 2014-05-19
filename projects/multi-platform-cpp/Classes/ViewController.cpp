//
//  ViewController.cpp
//  project
//
//  Created by  on 14-4-16.
//
//

#include "ViewController.h"

static int count = 0;

void ViewController::viewDidLoad()
{

    CAScrollView* scroll = new CAScrollView();
    scroll->initWithFrame(this->getView()->getBounds());
    this->getView()->addSubview(scroll);
    scroll->setViewSize(scroll->getBounds().size * 2);
    scroll->setMaximumZoomScale(3.0f);
    scroll->setMinimumZoomScale(0.5f);
    scroll->setBouncesZoom(false);
    
    CAImageView* v = CAImageView::createWithImage(CAImage::create("1.jpg"));
    v->setFrame(CCRect(0, 0, scroll->getViewSize().width, scroll->getViewSize().height));
    scroll->addSubview(v);
    
    
    ccColor3B color = ccRED;
    if (this->getTitle().compare("view1") == 0)
    {
        color = ccBLACK;
    }
    else if (this->getTitle().compare("view2") == 0)
    {
        scroll->setMaximumZoomScale(1.0f);
        scroll->setMinimumZoomScale(1.0f);
        scroll->setBounces(false);
    }
    else if (this->getTitle().compare("view3") == 0)
    {
        color = ccYELLOW;
    }
    else if (this->getTitle().compare("view4") == 0)
    {
        color = ccGRAY;
        
        scroll->setBounceHorizontal(false);
        
        
    }
    else if (this->getTitle().compare("view5") == 0)
    {
        color = ccRED;
        
        scroll->setBounces(false);
    }

    this->getView()->setColor(color);
}

bool ViewController::setAllowsSelection(CAButton* btn, CCPoint point)
{
    CCLog("%f   %f", point.x, point.y);
    return true;
}

void ViewController::viewDidUnload()
{
    this->getView()->removeAllSubviews();
}

void ViewController::touchUpInSide()
{
    ViewController* viewController2 = new ViewController();
    viewController2->init();
    viewController2->setTabBarItem(CATabBarItem::create("222", CAImage::create("e.png"), 101));
    viewController2->setNavigationBarItem(CANavigationBarItem::create(CCString::createWithFormat("ViewController %d", 0)->getCString()));
    viewController2->setTitle("view2");

    if (this->getNavigationController())
    {
        this->getNavigationController()->pushViewController(viewController2, true);
        return;
    }
    
    if (this->getTabBarController())
    {
        this->getTabBarController()->getNavigationController()->pushViewController(viewController2, true);
        return;
    }
}

void ViewController::touchUpInSide2()
{
    if (this->getNavigationController() && this->getNavigationController()->popViewControllerAnimated(true))
    {
        return;
    }
    
    if (this->getTabBarController() && this->getTabBarController()->getNavigationController()->popViewControllerAnimated(true))
    {
        return;
    }
}