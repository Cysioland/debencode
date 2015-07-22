/*
 * debencode.cpp
 *
 * Standalone command-line debencode utility
 *
 * debencode copyright (C) 2015 Joseph Durel [ jadematrix.art@gmail.com ]
 * debencode homepage: [ github.com/JadeMatrix/debencode ]
 */

/* INCLUDES *******************************************************************//******************************************************************************/

#include <iostream>
#include <map>
#include <fstream>

#include "debencode.hpp"

/* DECLARATIONS ***************************************************************//******************************************************************************/

enum parse_type
{
    INVALID,
    BENCODE,
    JSON,
    XML
};

/* DEFINITIONS ****************************************************************//******************************************************************************/

// #ifdef DEBENCODE_STANDALONE

inline int print_usage( const char* name )
{
    std::cout << "Usage: " << name << " [ bencode | json | xml ] file\n";
    return 0x01;
}

int main( int argc, char* argv[] )
{
    if( argc != 3 )
        return print_usage( argv[ 0 ] );
    else
    {
        // Quick get the decode type
        parse_type type = INVALID;
        {
            std::map< std::string, parse_type > chooser;
            
            chooser[ "bencode" ] = BENCODE;
            chooser[ "json"    ] = JSON;
            chooser[ "xml"     ] = XML;
            
            std::map< std::string,
                      parse_type >::iterator found = chooser.find( argv[ 1 ] );
            
            if( found != chooser.end() )
                type = found -> second;
        }
        
        if( type == INVALID )
            return print_usage( argv[ 0 ] );
        
        // Open file
        std::ifstream file( argv[ 2 ] );
        if( !file.is_open() )
        {
            std::cout << "Could not open file " << argv[ 2 ] << '\n';
            return 0x02;
        }
        
        // Parse file & create value object
        dbnc::value value( file );
        
        // Serialize to std::cout
        switch( type )
        {
        case BENCODE:
            value.serializeBencode( std::cout );
            break;
        case JSON:
            value.serializeJSON( std::cout );
            break;
        case XML:
            value.serializeXML( std::cout );
            break;
        default:
            // Never gets here
            break;
        }
    }
    
    return 0x00;
}

// #endif


