
#ifndef IMAGE_CLICK_TOOL_H
#define IMAGE_CLICK_TOOL_H

#include <rviz/tool.h>

// Mod by Tim:
#include "image_tracker_display.h"
#include "ImageTrackerInfo.h"

namespace Ogre
{
class SceneNode;
class Vector3;
}

namespace rviz
{
class VectorProperty;
class VisualizationManager;
class ViewportMouseEvent;
}

namespace rviz_plugin_tutorials
{

// BEGIN_TUTORIAL
// Here we declare our new subclass of rviz::Tool.  Every tool
// which can be added to the tool bar is a subclass of
// rviz::Tool.
class ImageClickTool: public rviz::Tool
{
Q_OBJECT
public:
  ImageClickTool();
  ~ImageClickTool();

  virtual void onInitialize();

  virtual void activate();
  virtual void deactivate();

  virtual int processMouseEvent( rviz::ViewportMouseEvent& event );

  virtual void load( const rviz::Config& config );
  virtual void save( rviz::Config config ) const;

private:
  void makeFlag( const Ogre::Vector3& position );

  std::vector<Ogre::SceneNode*> flag_nodes_;
  Ogre::SceneNode* moving_flag_node_;
  std::string flag_resource_;
  rviz::VectorProperty* current_flag_property_;

  // Mod by Tim:
  float calculateCommandedHeading(const float& currentHeadingDegrees, const float& clickedImgWidth, const float& imgWidth);


};
// END_TUTORIAL

} // end namespace rviz_plugin_tutorials

#endif // PLANT_FLAG_TOOL_H
