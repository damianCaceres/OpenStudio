/**********************************************************************
 *  Copyright (c) 2008-2016, Alliance for Sustainable Energy.
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

#ifndef MODEL_AIRTERMINALDUALDUCTVAVOUTDOORAIR_IMPL_HPP
#define MODEL_AIRTERMINALDUALDUCTVAVOUTDOORAIR_IMPL_HPP

#include "ModelAPI.hpp"
#include "Mixer_Impl.hpp"

namespace openstudio {
namespace model {

class Schedule;
class Node;
class DesignSpecificationOutdoorAir;

namespace detail {

  /** AirTerminalDualDuctVAVOutdoorAir_Impl is a Mixer_Impl that is the implementation class for AirTerminalDualDuctVAVOutdoorAir.*/
  class MODEL_API AirTerminalDualDuctVAVOutdoorAir_Impl : public Mixer_Impl {
   public:
    /** @name Constructors and Destructors */
    //@{

    AirTerminalDualDuctVAVOutdoorAir_Impl(const IdfObject& idfObject,
                                          Model_Impl* model,
                                          bool keepHandle);

    AirTerminalDualDuctVAVOutdoorAir_Impl(const openstudio::detail::WorkspaceObject_Impl& other,
                                          Model_Impl* model,
                                          bool keepHandle);

    AirTerminalDualDuctVAVOutdoorAir_Impl(const AirTerminalDualDuctVAVOutdoorAir_Impl& other,
                                          Model_Impl* model,
                                          bool keepHandle);

    virtual ~AirTerminalDualDuctVAVOutdoorAir_Impl() {}

    //@}
    /** @name Virtual Methods */
    //@{

    virtual const std::vector<std::string>& outputVariableNames() const override;

    virtual IddObjectType iddObjectType() const override;

    virtual std::vector<ScheduleTypeKey> getScheduleTypeKeys(const Schedule& schedule) const override;


    //@}
    /** @name Getters */
    //@{

    Schedule availabilitySchedule() const;

    boost::optional<double> maximumTerminalAirFlowRate() const;

    bool isMaximumTerminalAirFlowRateAutosized() const;

    std::string perPersonVentilationRateMode() const;

    bool controlForOutdoorAir() const;

    //@}
    /** @name Setters */
    //@{

  // Note Schedules are passed by reference, not const reference.
    bool setAvailabilitySchedule(Schedule& schedule);

    bool setMaximumTerminalAirFlowRate(double maximumTerminalAirFlowRate);

    void autosizeMaximumTerminalAirFlowRate();

    bool setControlForOutdoorAir(bool controlForOutdoorAir);

    bool setPerPersonVentilationRateMode(const std::string& perPersonVentilationRateMode);

    //@}
    /** @name Other */
    //@{

    virtual unsigned outletPort() const override;

    virtual unsigned inletPort(unsigned branchIndex) const override;

    virtual unsigned nextInletPort() const override;

    unsigned newInletPortAfterBranch(unsigned branchIndex) override;

    void removePortForBranch(unsigned branchIndex) override;

    bool addToNode(Node & node) override;

    std::vector<IdfObject> remove() override;

    virtual ModelObject clone(Model model) const override;

    bool isRemovable() const override;


    boost::optional<Node> outdoorAirInletNode() const;

    boost::optional<Node> recirculatedAirInletNode() const;

    //@}
   protected:
   private:
    REGISTER_LOGGER("openstudio.model.AirTerminalDualDuctVAVOutdoorAir");

  };

} // detail

} // model
} // openstudio

#endif // MODEL_AIRTERMINALDUALDUCTVAVOUTDOORAIR_IMPL_HPP

