/**********************************************************************
*  Copyright (c) 2008-2013, Alliance for Sustainable Energy.
*  All rights reserved.
*
*  This library is free software; you can redistribute it and/or
*  modify it under the terms of the GNU Lesser General Public
*  License as published by the Free Software Foundation; either
*  version 2.1 of the License, or (at your option) any later version.
*
*  This library is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
*  Lesser General Public License for more details.
*
*  You should have received a copy of the GNU Lesser General Public
*  License along with this library; if not, write to the Free Software
*  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
**********************************************************************/

#include <openstudio_lib/UtilityBillFuelTypeListView.hpp>

#include <openstudio_lib/BCLComponentItem.hpp>
#include <openstudio_lib/ModelObjectItem.hpp>

#include <model/Model_Impl.hpp>
#include <model/ModelObject_Impl.hpp>
#include <model/UtilityBill.hpp>
#include <model/UtilityBill_Impl.hpp>

#include <utilities/bcl/LocalBCL.hpp>
#include <utilities/core/Assert.hpp>

#include <iostream>

namespace openstudio {

UtilityBillFuelTypeListController::UtilityBillFuelTypeListController(const model::Model& model)
  : m_iddObjectType(model::UtilityBill::iddObjectType()), m_model(model)
{
  bool isConnected = false;
  isConnected = connect(model.getImpl<model::detail::Model_Impl>().get(), 
                        SIGNAL(addWorkspaceObject(boost::shared_ptr<openstudio::detail::WorkspaceObject_Impl>, const openstudio::IddObjectType&, const openstudio::UUID&)),
                        this,
                        SLOT(objectAdded(boost::shared_ptr<openstudio::detail::WorkspaceObject_Impl>, const openstudio::IddObjectType&, const openstudio::UUID&)),
                        Qt::QueuedConnection);
  OS_ASSERT(isConnected);

  isConnected = connect(model.getImpl<model::detail::Model_Impl>().get(), 
                        SIGNAL(removeWorkspaceObject(boost::shared_ptr<openstudio::detail::WorkspaceObject_Impl>, const openstudio::IddObjectType&, const openstudio::UUID&)),
                        this,
                        SLOT(objectRemoved(boost::shared_ptr<openstudio::detail::WorkspaceObject_Impl>, const openstudio::IddObjectType&, const openstudio::UUID&)),
                        Qt::QueuedConnection);
  OS_ASSERT(isConnected);

}

IddObjectType UtilityBillFuelTypeListController::iddObjectType() const
{
  return m_iddObjectType;
}

void UtilityBillFuelTypeListController::objectAdded(boost::shared_ptr<openstudio::detail::WorkspaceObject_Impl> impl, const openstudio::IddObjectType& iddObjectType, const openstudio::UUID& handle)
{
  if (iddObjectType == m_iddObjectType){
    std::vector<OSItemId> ids = this->makeVector();
    emit itemIds(ids);

    BOOST_FOREACH(const OSItemId& id, ids){
      if (id.itemId() == impl->handle().toString()){
        emit selectedItemId(id);
        break;
      }
    }
  }
}

void UtilityBillFuelTypeListController::objectRemoved(boost::shared_ptr<openstudio::detail::WorkspaceObject_Impl> impl, const openstudio::IddObjectType& iddObjectType, const openstudio::UUID& handle)
{
  if (iddObjectType == m_iddObjectType){
    emit itemIds(makeVector());
  }
}

std::vector<OSItemId> UtilityBillFuelTypeListController::makeVector()
{
  std::vector<OSItemId> result;

  // get objects by type
  std::vector<WorkspaceObject> workspaceObjects = m_model.getObjectsByType(m_iddObjectType);

  // sort by name
  std::sort(workspaceObjects.begin(), workspaceObjects.end(), WorkspaceObjectNameGreater());

  BOOST_FOREACH(WorkspaceObject workspaceObject,workspaceObjects){
    if (!workspaceObject.handle().isNull()){
      openstudio::model::ModelObject modelObject = workspaceObject.cast<openstudio::model::ModelObject>();
      if(boost::optional<model::UtilityBill> utilityBill = modelObject.optionalCast<model::UtilityBill>()) {
        result.push_back(modelObjectToItemId(modelObject, false));
      }
    }
  }

  return result;
}

UtilityBillFuelTypeListView::UtilityBillFuelTypeListView(const model::Model& model, 
                                         bool addScrollArea,
                                         QWidget * parent )
  : OSItemList(new UtilityBillFuelTypeListController(model,addScrollArea)
{ 
}  

boost::optional<openstudio::model::ModelObject> UtilityBillFuelTypeListView::selectedModelObject() const
{
  OSItem* selectedItem = this->selectedItem();
  ModelObjectItem* modelObjectItem = qobject_cast<ModelObjectItem*>(selectedItem);
  if (modelObjectItem){
    return modelObjectItem->modelObject();
  }
  return boost::none;
}

IddObjectType UtilityBillFuelTypeListView::iddObjectType() const
{
  OSVectorController* vectorController = this->vectorController();
  UtilityBillFuelTypeListController* utilityBillListController = qobject_cast<UtilityBillFuelTypeListController*>(vectorController);
  OS_ASSERT(utilityBillListController);
  return utilityBillListController->iddObjectType();
}

} // openstudio

