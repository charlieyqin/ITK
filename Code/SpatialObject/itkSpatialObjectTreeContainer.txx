/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    itkSpatialObjectTreeContainer.txx
  Language:  C++
  Date:      $Date$
  Version:   $Revision$

  Copyright (c) Insight Software Consortium. All rights reserved.
  See ITKCopyright.txt or http://www.itk.org/HTML/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#ifndef _itkSpatialObjectTreeContainer_txx
#define _itkSpatialObjectTreeContainer_txx

#include "itkSpatialObjectTreeContainer.h"

namespace itk
{

/** Constructor */
template <unsigned int TDimension>
SpatialObjectTreeContainer<TDimension>::SpatialObjectTreeContainer()
{
}

/** Destructor */
template <unsigned int TDimension>
SpatialObjectTreeContainer<TDimension>::~SpatialObjectTreeContainer() 
{
}

/** Set the root */
template <unsigned int TDimension>
bool 
SpatialObjectTreeContainer<TDimension>::SetRoot(SpatialObjectPointer element)
{
  if(m_Root)
    {
    std::cout << "This tree has already a root" << std::endl;
    return false;
    }
  
  if(element->GetTreeNode())
    {
    m_Root = element->GetTreeNode();
    }
  else
    {
    m_Root = SpatialObjectTreeNode<TDimension>::New();
    m_Root->Set(element);
    }
  return true;
}

} // namespace itk

#endif
