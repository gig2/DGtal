/**
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as
 *  published by the Free Software Foundation, either version 3 of the
 *  License, or  (at your option) any later version.
 *
 *  This program is distributed‰ in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 **/

#pragma once

/**
 * @file CDigitialOrientedShape.h
 * @author David Coeurjolly (\c david.coeurjolly@liris.cnrs.fr )
 * Laboratoire d'InfoRmatique en Image et Systèmes d'information - LIRIS (CNRS, UMR 5205), CNRS, France
 *
 * @date 2011/10/20
 *
 * Header file for concept CEuclideanOrientedShape.cpp
 *
 * This file is part of the DGtal library.
 */

#if defined(CEuclideanOrientedShape_RECURSES)
#error Recursive header files inclusion detected in CEuclideanOrientedShape.h
#else // defined(CEuclideanOrientedShape_RECURSES)
/** Prevents recursive inclusion of headers. */
#define CEuclideanOrientedShape_RECURSES

#if !defined CEuclideanOrientedShape_h
/** Prevents repeated inclusion of headers. */
#define CEuclideanOrientedShape_h

//////////////////////////////////////////////////////////////////////////////
// Inclusions
#include <iostream>
#include "DGtal/base/Common.h"
#include "DGtal/kernel/CCommutativeRing.h"
//////////////////////////////////////////////////////////////////////////////

namespace DGtal
{

  /////////////////////////////////////////////////////////////////////////////
  // class CEuclideanOrientedShape
  /**
     Description of \b concept '\b CEuclideanOrientedShape' <p>
     @ingroup Concepts
     @brief Aim: characterizes models of digital oriented shapes. For example,
     models should provide an orientation method  for  real
     points. Returned value type corresponds to  DGtal::Orientation.

     <p> Refinement of
    
     <p> Associated types :
    - RealPoint: type for real points.

     <p> Notation
     - \t X : A type that is a model of CEuclideanOrientedShape
     - \t x, \t y : object of type X
    
     <p> Definitions
    
     <p> Valid expressions and semantics <br>
     <table> 
      <tr> 
        <td class=CName> \b Name </td> 
        <td class=CExpression> \b Expression </td>
        <td class=CRequirements> \b Type requirements </td> 
        <td class=CReturnType> \b Return type </td>
        <td class=CPrecondition> \b Precondition </td> 
        <td class=CSemantics> \b Semantics </td> 
        <td class=CPostCondition> \b Postcondition </td> 
        <td class=CComplexity> \b Complexity </td>
      </tr>
      <tr> 
        <td class=CName> Orientation method           </td> 
        <td class=CExpression>  x.orientation( aPoint)    </td>
        <td class=CRequirements> aPoint of type const RealPoint &   </td> 
        <td class=CReturnType> DGtal::Orientation     </td>
        <td class=CPrecondition>    </td> 
        <td class=CSemantics> return the orientation of a point @c
     aPoint according to the shape. Orientation values can be {DGtal::INSIDE,
     DGtal::ON or DGtal::OUTSIDE}.      </Td> 
        <td class=CPostCondition>   </td> 
        <td class=CComplexity>      </td>
      </tr>
    
     </table>
    
     <p> Invariants <br>
    
     <p> Models <br>

      Parametric and implicit shapes in the DGtal shape factory, 

     <p> Notes <br>

     @tparam T the type that should be a model of CEuclideanOrientedShape.
   */
  template <typename T> 
  struct CEuclideanOrientedShape
  {
    // ----------------------- Concept checks ------------------------------
  public:
    // 1. define first provided types (i.e. inner types), like
    typedef typename T::RealPoint RealPoint;
   
    // 2. then check the presence of data members, operators and methods with
    BOOST_CONCEPT_USAGE( CEuclideanOrientedShape )
    {
      ConceptUtils::sameType( myA, myX.orientation( p ));
    }
    // ------------------------- Private Datas --------------------------------
  private:
    T myX; // only if T is default constructible.
    Orientation myA;
    RealPoint p;
    
    // ------------------------- Internals ------------------------------------
  private:
    
  }; // end of concept CEuclideanOrientedShape
  
} // namespace DGtal

//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#endif // !defined CEuclideanOrientedShape_h

#undef CEuclideanOrientedShape_RECURSES
#endif // else defined(CEuclideanOrientedShape_RECURSES)