/**********************************************************************
 *  Copyright (c) 2008-2015, Alliance for Sustainable Energy.
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

#ifndef MODEL_ZONEAIRMASSFLOWCONSERVATION_IMPL_HPP
#define MODEL_ZONEAIRMASSFLOWCONSERVATION_IMPL_HPP

#include "ModelAPI.hpp"
#include "ModelObject_Impl.hpp"

namespace openstudio {
namespace model {

namespace detail {

  /** ZoneAirMassFlowConservation_Impl is a ModelObject_Impl that is the implementation class for ZoneAirMassFlowConservation.*/
  class MODEL_API ZoneAirMassFlowConservation_Impl : public ModelObject_Impl {
   public:
    /** @name Constructors and Destructors */
    //@{

    ZoneAirMassFlowConservation_Impl(const IdfObject& idfObject,
                                     Model_Impl* model,
                                     bool keepHandle);

    ZoneAirMassFlowConservation_Impl(const openstudio::detail::WorkspaceObject_Impl& other,
                                     Model_Impl* model,
                                     bool keepHandle);

    ZoneAirMassFlowConservation_Impl(const ZoneAirMassFlowConservation_Impl& other,
                                     Model_Impl* model,
                                     bool keepHandle);

    virtual ~ZoneAirMassFlowConservation_Impl() {}

    //@}
    /** @name Virtual Methods */
    //@{

    virtual const std::vector<std::string>& outputVariableNames() const override;

    virtual IddObjectType iddObjectType() const override;

    //@}
    /** @name Getters */
    //@{

    bool adjustZoneMixingForZoneAirMassFlowBalance() const;

    bool isAdjustZoneMixingForZoneAirMassFlowBalanceDefaulted() const;

    std::string sourceZoneInfiltrationTreatment() const;

    bool isSourceZoneInfiltrationTreatmentDefaulted() const;
    
    std::string infiltrationBalancingMethod() const;

    bool isInfiltrationBalancingMethodDefaulted() const;

    std::string infiltrationBalancingZones() const;

    bool isInfiltrationBalancingZonesDefaulted() const;

    //@}
    /** @name Setters */
    //@{

    void setAdjustZoneMixingForZoneAirMassFlowBalance(bool adjustZoneMixingForZoneAirMassFlowBalance);

    void resetAdjustZoneMixingForZoneAirMassFlowBalance();

    bool setSourceZoneInfiltrationTreatment(const std::string& sourceZoneInfiltrationTreatment);

    void resetSourceZoneInfiltrationTreatment();

    bool setInfiltrationBalancingMethod(const std::string& infiltrationBalancingMethod);

    void resetInfiltrationBalancingMethod();

    bool setInfiltrationBalancingZones(const std::string& infiltrationBalancingZones);

    void resetInfiltrationBalancingZones();

    //@}
    /** @name Other */
    //@{

    //@}
   protected:
   private:
    REGISTER_LOGGER("openstudio.model.ZoneAirMassFlowConservation");
  };

} // detail

} // model
} // openstudio

#endif // MODEL_ZONEAIRMASSFLOWCONSERVATION_IMPL_HPP

