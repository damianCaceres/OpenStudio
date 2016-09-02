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

#include "BCLMeasureOutput.hpp"

#include "../core/Assert.hpp"

#include <QDomDocument>
#include <QDomElement>

namespace openstudio{

  BCLMeasureOutput::BCLMeasureOutput(const QDomElement& element)
  {
    // todo: escape name
    m_name = element.firstChildElement("name").firstChild().nodeValue().toStdString();

    m_displayName = element.firstChildElement("display_name").firstChild().nodeValue().toStdString();

    if (!element.firstChildElement("short_name").isNull()){
      m_shortName = element.firstChildElement("short_name").firstChild().nodeValue().toStdString();
    }

    if (!element.firstChildElement("description").isNull()){
      m_description = element.firstChildElement("description").firstChild().nodeValue().toStdString();
    }

    m_type = element.firstChildElement("type").firstChild().nodeValue().toStdString();

    if (!element.firstChildElement("units").isNull()){
      m_units = element.firstChildElement("units").firstChild().nodeValue().toStdString();
    }

    QString test = element.firstChildElement("model_dependent").firstChild().nodeValue();
    if (test == "true"){
      m_modelDependent = true;
    } else {
      m_modelDependent = false;
    }

  }

  BCLMeasureOutput::BCLMeasureOutput(const std::string& name, const std::string& displayName,
                                         const boost::optional<std::string>& shortName,
                                         const boost::optional<std::string>& description,
                                         const std::string& type, const boost::optional<std::string>& units,
                                         bool modelDependent)
                                         : m_name(name), m_displayName(displayName), 
                                         m_shortName(shortName), m_description(description), 
                                         m_type(type), m_units(units), m_modelDependent(modelDependent)
  {
  }

  std::string BCLMeasureOutput::name() const
  {
    return m_name;
  }

  std::string BCLMeasureOutput::displayName() const
  {
    return m_displayName;
  }

  boost::optional<std::string> BCLMeasureOutput::shortName() const
  {
    return m_shortName;
  }

  boost::optional<std::string> BCLMeasureOutput::description() const
  {
    return m_description;
  }

  std::string BCLMeasureOutput::type() const
  {
    return m_type;
  }

  boost::optional<std::string> BCLMeasureOutput::units() const
  {
    return m_units;
  }

  bool BCLMeasureOutput::modelDependent() const
  {
    return m_modelDependent;
  }

  void BCLMeasureOutput::writeValues(QDomDocument& doc, QDomElement& element) const
  {
    QDomElement nameElement = doc.createElement("name");
    element.appendChild(nameElement);
    nameElement.appendChild(doc.createTextNode(toQString(m_name)));

    QDomElement displayNameElement = doc.createElement("display_name");
    element.appendChild(displayNameElement);
    displayNameElement.appendChild(doc.createTextNode(toQString(m_displayName)));

    if (m_shortName){
      QDomElement shortNameElement = doc.createElement("short_name");
      element.appendChild(shortNameElement);
      shortNameElement.appendChild(doc.createTextNode(toQString(*m_shortName)));
    }

    if (m_description){
      QDomElement descriptionElement = doc.createElement("description");
      element.appendChild(descriptionElement);
      descriptionElement.appendChild(doc.createTextNode(toQString(*m_description)));
    }

    QDomElement typeElement = doc.createElement("type");
    element.appendChild(typeElement);
    typeElement.appendChild(doc.createTextNode(toQString(m_type)));

    if (m_units){
      QDomElement unitsElement = doc.createElement("units");
      element.appendChild(unitsElement);
      unitsElement.appendChild(doc.createTextNode(toQString(*m_units)));
    }

    QDomElement modelDependentElement = doc.createElement("model_dependent");
    element.appendChild(modelDependentElement);
    modelDependentElement.appendChild(doc.createTextNode(m_modelDependent ? "true" : "false"));
  }

  bool BCLMeasureOutput::operator == (const BCLMeasureOutput& other) const
  {
    if (m_name != other.name()){
      return false;
    }

    if (m_displayName != other.displayName()){
      return false;
    }

    if (m_shortName && !other.shortName()){
      return false;
    } else if (!m_shortName && other.shortName()){
      return false;
    } else if (m_shortName && other.shortName()){
      if (m_shortName.get() != other.shortName().get()){
        return false;
      }
    }

    if (m_description && !other.description()){
      return false;
    } else if (!m_description && other.description()){
      return false;
    } else if (m_description && other.description()){
      if (m_description.get() != other.description().get()){
        return false;
      }
    }

    if (m_type != other.type()){
      return false;
    }

    if (m_units && !other.units()){
      return false;
    } else if (!m_units && other.units()){
      return false;
    } else if (m_units && other.units()){
      if (m_units.get() != other.units().get()){
        return false;
      }
    }

    if (m_modelDependent != other.modelDependent()){
      return false;
    }

    return true;
  }

  std::ostream& operator<<(std::ostream& os, const BCLMeasureOutput& argument)
  {
    QDomDocument doc;
    QDomElement element = doc.createElement(QString("Output"));
    doc.appendChild(element);
    argument.writeValues(doc, element);

    QString str;
    QTextStream qts(&str);
    doc.save(qts, 2);
    os << str.toStdString();
    return os;
  }


} // openstudio