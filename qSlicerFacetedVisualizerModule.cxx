/*==============================================================================

  Program: 3D Slicer

  Portions (c) Copyright Brigham and Women's Hospital (BWH) All Rights Reserved.

  See COPYRIGHT.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

==============================================================================*/

// Qt includes
#include <QtPlugin>

// FacetedVisualizer Logic includes
#include <vtkSlicerFacetedVisualizerLogic.h>

// FacetedVisualizer includes
#include "qSlicerFacetedVisualizerModule.h"
#include "qSlicerFacetedVisualizerModuleWidget.h"

//-----------------------------------------------------------------------------
Q_EXPORT_PLUGIN2(qSlicerFacetedVisualizerModule, qSlicerFacetedVisualizerModule);

//-----------------------------------------------------------------------------
/// \ingroup Slicer_QtModules_FacetedVisualizer
class qSlicerFacetedVisualizerModulePrivate
{
public:
  qSlicerFacetedVisualizerModulePrivate();
};

//-----------------------------------------------------------------------------
// qSlicerFacetedVisualizerModulePrivate methods

//-----------------------------------------------------------------------------
qSlicerFacetedVisualizerModulePrivate::qSlicerFacetedVisualizerModulePrivate()
{
}

//-----------------------------------------------------------------------------
// qSlicerFacetedVisualizerModule methods

//-----------------------------------------------------------------------------
qSlicerFacetedVisualizerModule::qSlicerFacetedVisualizerModule(QObject* _parent)
  : Superclass(_parent)
  , d_ptr(new qSlicerFacetedVisualizerModulePrivate)
{
}

//-----------------------------------------------------------------------------
QStringList qSlicerFacetedVisualizerModule::categories()const
{
  return QStringList() << "Developer Tools";
}

//-----------------------------------------------------------------------------
qSlicerFacetedVisualizerModule::~qSlicerFacetedVisualizerModule()
{
}

//-----------------------------------------------------------------------------
QString qSlicerFacetedVisualizerModule::helpText()const
{
  QString help = 
    "This template module is meant to be used with the"
    "with the ModuleWizard.py script distributed with the"
    "Slicer source code (starting with version 4)."
    "Developers can generate their own source code using the"
    "wizard and then customize it to fit their needs.";
  return help;
}

//-----------------------------------------------------------------------------
QString qSlicerFacetedVisualizerModule::acknowledgementText()const
{
  return "This work was supported by NAMIC, NAC, and the Slicer Community...";
}

//-----------------------------------------------------------------------------
QStringList qSlicerFacetedVisualizerModule::contributors()const
{
  QStringList moduleContributors;
  moduleContributors << QString("Harini Veeraraghavan (General Electric Research)");
  // moduleContributors << QString("Richard Roe (Other organization Inc.)");
  // ...
  return moduleContributors;
}

//-----------------------------------------------------------------------------
QIcon qSlicerFacetedVisualizerModule::icon()const
{
  return QIcon(":/Icons/FacetedVisualizer.png");
}

//-----------------------------------------------------------------------------
void qSlicerFacetedVisualizerModule::setup()
{
  this->Superclass::setup();
}

//-----------------------------------------------------------------------------
qSlicerAbstractModuleRepresentation * qSlicerFacetedVisualizerModule::createWidgetRepresentation()
{
  return new qSlicerFacetedVisualizerModuleWidget;
}

//-----------------------------------------------------------------------------
vtkMRMLAbstractLogic* qSlicerFacetedVisualizerModule::createLogic()
{
  return vtkSlicerFacetedVisualizerLogic::New();
}