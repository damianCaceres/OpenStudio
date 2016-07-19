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

#ifndef MODEL_SCREEN_IMPL_HPP
#define MODEL_SCREEN_IMPL_HPP

#include "ModelAPI.hpp"
#include "ShadingMaterial_Impl.hpp"

#include "../utilities/units/Quantity.hpp"
#include "../utilities/units/OSOptionalQuantity.hpp"

namespace openstudio {
namespace model {

namespace detail {

  /** Screen_Impl is a ShadingMaterial_Impl that is the implementation class for Screen.*/
  class MODEL_API Screen_Impl : public ShadingMaterial_Impl {
    

    
    
    

    
    
    

    
    
    

    
    
    
    

    
    
    
    

    
    
    

    
    
    

    
    
    
    

    
    
    
    

    
    
    
    

    
    
    
    

    
    
    
    

    
    
    

    // TODO: Add relationships for objects related to this one, but not pointed to by the underlying data.
    //       Such relationships can be generated by the GenerateRelationships.rb script.
   public:
    /** @name Constructors and Destructors */
    //@{

    Screen_Impl(const IdfObject& idfObject,
                Model_Impl* model,
                bool keepHandle);

    Screen_Impl(const openstudio::detail::WorkspaceObject_Impl& other,
                Model_Impl* model,
                bool keepHandle);

    Screen_Impl(const Screen_Impl& other,
                Model_Impl* model,
                bool keepHandle);

    virtual ~Screen_Impl() {}

    //@}

    /** @name Virtual Methods */
    //@{

    virtual const std::vector<std::string>& outputVariableNames() const override;

    virtual IddObjectType iddObjectType() const override;

    //@}
    /** @name Getters */
    //@{

    /** Get the thickness of the material. For now is equivalent to screen material diameter. 
     *  However, actual thickness of construction should not use this number directly, but should 
     *  also factor in the screen to glass distance. */
    virtual double thickness() const override;

    /** The conductivitiy of the material in W/m*K. */
    double thermalConductivity() const;

    /** The conductance of the material in W/m^2*K. */
    double thermalConductance() const;

    /** The resistivity of the material in m*K/W. */
    double thermalResistivity() const;

    /** The resistance of the material in m^2*K/W. */
    double thermalResistance() const;

    virtual boost::optional<double> getVisibleTransmittance() const override;

    std::string reflectedBeamTransmittanceAccountingMethod() const;

    bool isReflectedBeamTransmittanceAccountingMethodDefaulted() const;

    double diffuseSolarReflectance() const;

    Quantity getDiffuseSolarReflectance(bool returnIP=false) const;

    double diffuseVisibleReflectance() const;

    Quantity getDiffuseVisibleReflectance(bool returnIP=false) const;

    double thermalHemisphericalEmissivity() const;

    Quantity getThermalHemisphericalEmissivity(bool returnIP=false) const;

    bool isThermalHemisphericalEmissivityDefaulted() const;

    double conductivity() const;

    Quantity getConductivity(bool returnIP=false) const;

    bool isConductivityDefaulted() const;

    double screenMaterialSpacing() const;

    Quantity getScreenMaterialSpacing(bool returnIP=false) const;

    double screenMaterialDiameter() const;

    Quantity getScreenMaterialDiameter(bool returnIP=false) const;

    double screentoGlassDistance() const;

    Quantity getScreentoGlassDistance(bool returnIP=false) const;

    bool isScreentoGlassDistanceDefaulted() const;

    double topOpeningMultiplier() const;

    Quantity getTopOpeningMultiplier(bool returnIP=false) const;

    bool isTopOpeningMultiplierDefaulted() const;

    double bottomOpeningMultiplier() const;

    Quantity getBottomOpeningMultiplier(bool returnIP=false) const;

    bool isBottomOpeningMultiplierDefaulted() const;

    double leftSideOpeningMultiplier() const;

    Quantity getLeftSideOpeningMultiplier(bool returnIP=false) const;

    bool isLeftSideOpeningMultiplierDefaulted() const;

    double rightSideOpeningMultiplier() const;

    Quantity getRightSideOpeningMultiplier(bool returnIP=false) const;

    bool isRightSideOpeningMultiplierDefaulted() const;

    std::string angleofResolutionforScreenTransmittanceOutputMap() const;

    bool isAngleofResolutionforScreenTransmittanceOutputMapDefaulted() const;

    //@}
    /** @name Setters */
    //@{

    /** Set thickness to value (m). For now is equivalent to setting screen material diameter. */
    virtual bool setThickness(double value) override;

    /** Sets the conductivity of the material in W/m*K, if possible. */
    bool setThermalConductivity(double value);

    /** Sets the resistivity of the material in m*K/W, if possible. */
    bool setThermalResistivity(double value);

    bool setReflectedBeamTransmittanceAccountingMethod(std::string reflectedBeamTransmittanceAccountingMethod);

    void resetReflectedBeamTransmittanceAccountingMethod();

    bool setDiffuseSolarReflectance(double diffuseSolarReflectance);

    bool setDiffuseSolarReflectance(const Quantity& diffuseSolarReflectance);

    bool setDiffuseVisibleReflectance(double diffuseVisibleReflectance);

    bool setDiffuseVisibleReflectance(const Quantity& diffuseVisibleReflectance);

    bool setThermalHemisphericalEmissivity(double thermalHemisphericalEmissivity);

    bool setThermalHemisphericalEmissivity(const Quantity& thermalHemisphericalEmissivity);

    void resetThermalHemisphericalEmissivity();

    bool setConductivity(double conductivity);

    bool setConductivity(const Quantity& conductivity);

    void resetConductivity();

    bool setScreenMaterialSpacing(double screenMaterialSpacing);

    bool setScreenMaterialSpacing(const Quantity& screenMaterialSpacing);

    bool setScreenMaterialDiameter(double screenMaterialDiameter);

    bool setScreenMaterialDiameter(const Quantity& screenMaterialDiameter);

    bool setScreentoGlassDistance(double screentoGlassDistance);

    bool setScreentoGlassDistance(const Quantity& screentoGlassDistance);

    void resetScreentoGlassDistance();

    bool setTopOpeningMultiplier(double topOpeningMultiplier);

    bool setTopOpeningMultiplier(const Quantity& topOpeningMultiplier);

    void resetTopOpeningMultiplier();

    bool setBottomOpeningMultiplier(double bottomOpeningMultiplier);

    bool setBottomOpeningMultiplier(const Quantity& bottomOpeningMultiplier);

    void resetBottomOpeningMultiplier();

    bool setLeftSideOpeningMultiplier(double leftSideOpeningMultiplier);

    bool setLeftSideOpeningMultiplier(const Quantity& leftSideOpeningMultiplier);

    void resetLeftSideOpeningMultiplier();

    bool setRightSideOpeningMultiplier(double rightSideOpeningMultiplier);

    bool setRightSideOpeningMultiplier(const Quantity& rightSideOpeningMultiplier);

    void resetRightSideOpeningMultiplier();

    bool setAngleofResolutionforScreenTransmittanceOutputMap(std::string angleofResolutionforScreenTransmittanceOutputMap);

    void resetAngleofResolutionforScreenTransmittanceOutputMap();

    //@}
    /** @name Other */
    //@{

    //@}
   protected:
   private:
    REGISTER_LOGGER("openstudio.model.Screen");

    openstudio::Quantity diffuseSolarReflectance_SI() const;
    openstudio::Quantity diffuseSolarReflectance_IP() const;
    openstudio::Quantity diffuseVisibleReflectance_SI() const;
    openstudio::Quantity diffuseVisibleReflectance_IP() const;
    openstudio::Quantity thermalHemisphericalEmissivity_SI() const;
    openstudio::Quantity thermalHemisphericalEmissivity_IP() const;
    openstudio::Quantity conductivity_SI() const;
    openstudio::Quantity conductivity_IP() const;
    openstudio::Quantity screenMaterialSpacing_SI() const;
    openstudio::Quantity screenMaterialSpacing_IP() const;
    openstudio::Quantity screenMaterialDiameter_SI() const;
    openstudio::Quantity screenMaterialDiameter_IP() const;
    openstudio::Quantity screentoGlassDistance_SI() const;
    openstudio::Quantity screentoGlassDistance_IP() const;
    openstudio::Quantity topOpeningMultiplier_SI() const;
    openstudio::Quantity topOpeningMultiplier_IP() const;
    openstudio::Quantity bottomOpeningMultiplier_SI() const;
    openstudio::Quantity bottomOpeningMultiplier_IP() const;
    openstudio::Quantity leftSideOpeningMultiplier_SI() const;
    openstudio::Quantity leftSideOpeningMultiplier_IP() const;
    openstudio::Quantity rightSideOpeningMultiplier_SI() const;
    openstudio::Quantity rightSideOpeningMultiplier_IP() const;
    std::vector<std::string> reflectedBeamTransmittanceAccountingMethodValues() const;
    std::vector<std::string> angleofResolutionforScreenTransmittanceOutputMapValues() const;
  };

} // detail

} // model
} // openstudio

#endif // MODEL_SCREEN_IMPL_HPP

