/**
 * @file testAdjacency.cpp
 * @ingroup Tests
 * @author Jacques-Olivier Lachaud (\c jacques-olivier.lachaud@univ-savoie.fr )
 * Laboratory of Mathematics (CNRS, UMR 5807), University of Savoie, France
 *
 * @date 2010/07/04
 *
 * Functions for testing class Adjacency.
 *
 * This file is part of the DGtal library.
 */

///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include "DGtal/base/Common.h"
#include "DGtal/kernel/SpaceND.h"
#include "DGtal/topology/MetricAdjacency.h"
///////////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace DGtal;

/**
 * @example testAdjacency.cpp
 *
 * This file test the standard digital adjacencies, the one based on a
 * metric. We have the classical 4- and 8- adjacencies in 2D, the 6-,
 * 18- and 26- in 3D.
 */

///////////////////////////////////////////////////////////////////////////////
// Functions for testing class Adjacency.
///////////////////////////////////////////////////////////////////////////////
/**
 * Example of a test. To be completed.
 *
 */
bool testMetricAdjacency()
{
  unsigned int nbok = 0;
  unsigned int nb = 0;
  
  typedef SpaceND<int,3> Space3D;
  typedef Space3D::Point Point;
  // typedef MetricAdjacency<Space3D,1> Adj6;
  // typedef MetricAdjacency<Space3D,2> Adj18;
  // typedef MetricAdjacency<Space3D,3> Adj26;
  typedef Z3Adj6 Adj6;
  typedef Z3Adj18 Adj18;
  typedef Z3Adj26 Adj26;
  Point p( 3, -5, 10 );


  trace.beginBlock ( "Testing neighborhood of" );
  Adj6::selfDisplay( trace.info() );
  trace.info() << " p = " << p << std::endl;
  vector<Point> neigh6;
  back_insert_iterator< vector<Point> > bii6( neigh6 );
  Adj6::writeNeighborhood( p, bii6 );
  nbok += neigh6.size() == 7 ? 1 : 0; 
  nb++;
  trace.info() << "(" << nbok << "/" << nb << ") "
	       << "Card(6-neigh): " << neigh6.size() 
	       << "== 7 ?" << std::endl;
  trace.beginBlock ( "Enumerating neighbors." );
  unsigned int nb_correct = 0;
  for ( unsigned int i = 0; i < neigh6.size(); ++i )
    {
      if ( Adj6::isProperlyAdjacentTo( p, neigh6[ i ] ) )
	{
	  trace.info() << neigh6[ i ] << "* " << std::endl;
	  ++nb_correct;
	}
      else
	trace.info() << neigh6[ i ] << "- " << std::endl;
    }
  trace.endBlock();
  nbok += nb_correct == 6 ? 1 : 0; 
  nb++;
  trace.info() << "(" << nbok << "/" << nb << ") "
	       << "Within, #proper adjacent : " << nb_correct
	       << "== 6 ?" << std::endl;
  trace.endBlock();



  trace.beginBlock ( "Testing neighborhood of" );
  Adj18::selfDisplay( trace.info() );
  trace.info() << " p = " << p << std::endl;
  vector<Point> neigh18;
  back_insert_iterator< vector<Point> > bii18( neigh18 );
  Adj18::writeNeighborhood( p, bii18 );
  nbok += neigh18.size() == 19 ? 1 : 0; 
  nb++;
  trace.info() << "(" << nbok << "/" << nb << ") "
	       << "Card(18-neigh): " << neigh18.size() 
	       << "== 19 ?" << std::endl;
  trace.beginBlock ( "Enumerating neighbors." );
  nb_correct = 0;
  for ( unsigned int i = 0; i < neigh18.size(); ++i )
    {
      if ( Adj18::isProperlyAdjacentTo( p, neigh18[ i ] ) )
	{
	  trace.info() << neigh18[ i ] << "* " << std::endl;
	  ++nb_correct;
	}
      else
	trace.info() << neigh18[ i ] << "- " << std::endl;
    }
  trace.endBlock();
  nbok += nb_correct == 18 ? 1 : 0; 
  nb++;
  trace.info() << "(" << nbok << "/" << nb << ") "
	       << "Within, #proper adjacent : " << nb_correct
	       << "== 18 ?" << std::endl;
  trace.endBlock();


  trace.beginBlock ( "Testing neighborhood of" );
  Adj26::selfDisplay( trace.info() );
  trace.info() << " p = " << p << std::endl;
  vector<Point> neigh26;
  back_insert_iterator< vector<Point> > bii26( neigh26 );
  Adj26::writeNeighborhood( p, bii26 );
  nbok += neigh26.size() == 27 ? 1 : 0; 
  nb++;
  trace.info() << "(" << nbok << "/" << nb << ") "
	       << "Card(26-neigh): " << neigh26.size() 
	       << "== 27 ?" << std::endl;
  trace.beginBlock ( "Enumerating neighbors." );
  nb_correct = 0;
  for ( unsigned int i = 0; i < neigh26.size(); ++i )
    {
      if ( Adj26::isProperlyAdjacentTo( p, neigh26[ i ] ) )
	{
	  trace.info() << neigh26[ i ] << "* " << std::endl;
	  ++nb_correct;
	}
      else
	trace.info() << neigh26[ i ] << "- " << std::endl;
    }
  trace.endBlock();
  nbok += nb_correct == 26 ? 1 : 0; 
  nb++;
  trace.info() << "(" << nbok << "/" << nb << ") "
	       << "Within, #proper adjacent : " << nb_correct
	       << "== 26 ?" << std::endl;
  trace.endBlock();

  return nbok == nb;
}

///////////////////////////////////////////////////////////////////////////////
// Standard services - public :

int main( int argc, char** argv )
{
  trace.beginBlock ( "Testing class Adjacency" );
  trace.info() << "Args:";
  for ( int i = 0; i < argc; ++i )
    trace.info() << " " << argv[ i ];
  trace.info() << endl;

  bool res = testMetricAdjacency(); // && ... other tests
  trace.emphase() << ( res ? "Passed." : "Error." ) << endl;
  trace.endBlock();
  return res ? 0 : 1;
}
//                                                                           //
///////////////////////////////////////////////////////////////////////////////