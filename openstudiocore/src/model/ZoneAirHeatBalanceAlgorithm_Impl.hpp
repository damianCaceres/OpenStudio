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

#ifndef MODEL_ZONEAIRHEATBALANCEALGORITHM_IMPL_HPP
#define MODEL_ZONEAIRHEATBALANCEALGORITHM_IMPL_HPP

#include "ModelAPI.hpp"
#include "ModelObject_Impl.hpp"

namespace openstudio {
namespace model {

namespace detail {

  /** ZoneAirHeatBalanceAlgorithm_Impl is a ModelObject_Impl that is the implementation class for ZoneAirHeatBalanceAlgorithm.*/
  class MODEL_API ZoneAirHeatBalanceAlgorithm_Impl : public ModelObject_Impl {
    

    
    
    

    // TODO: Add relationships for objects related to this one, but not pointed to by the underlying data.
    //       Such relationships can be generated by the GenerateRelationships.rb script.
   public:
    /** @name Constructors and Destructors */
    //@{

    // constructor
    ZoneAirHeatBalanceAlgorithm_Impl(const IdfObject& idfObject,
                                     Model_Impl* model,
                                     bool keepHandle);

    // construct from workspace
    ZoneAirHeatBalanceAlgorithm_Impl(const openstudio::detail::WorkspaceObject_Impl& other,
                                     Model_Impl* model,
                                     bool keepHandle);

    // clone copy constructor
    ZoneAirHeatBalanceAlgorithm_Impl(const ZoneAirHeatBalanceAlgorithm_Impl& other,
                                     Model_Impl* model,
                                     bool keepHandle);

    // virtual destructor
    virtual ~ZoneAirHeatBalanceAlgorithm_Impl() {}

    //@}

    /** @name Virtual Methods */
    //@{

    // return the parent object in the hierarchy
    virtual boost::optional<ParentObject> parent() const override;

    // set the parent, child may have to call methods on the parent
    virtual bool setParent(ParentObject& newParent) override;

    // Get all output variable names that could be associated with this object.
    virtual const std::vector<std::string>& outputVariableNames() const override;

    virtual IddObjectType iddObjectType() const override;

    //@}
    /** @name Getters */
    //@{

    std::string algorithm() const;

    bool isAlgorithmDefaulted() const;

    //@}
    /** @name Setters */
    //@{

    bool setAlgorithm(std::string algorithm);

    void resetAlgorithm();

    //@}
    /** @name Other */
    //@{

    //@}
   protected:

   private:

    REGISTER_LOGGER("openstudio.model.ZoneAirHeatBalanceAlgorithm");

    std::vector<std::string> validAlgorithmValues() const;
  };

} // detail

} // model
} // openstudio

#endif // MODEL_ZONEAIRHEATBALANCEALGORITHM_IMPL_HPP

