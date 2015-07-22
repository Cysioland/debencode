/*
 * dbnc.cpp
 *
 * Implementation/definitions for the dbnc::value class
 *
 * debencode copyright (C) 2015 Joseph Durel [ jadematrix.art@gmail.com ]
 * debencode homepage: [ github.com/JadeMatrix/debencode ]
 */

/* INCLUDES *******************************************************************//******************************************************************************/

#include "debencode.hpp"

/* DEFINITIONS ****************************************************************//******************************************************************************/

namespace dbnc
{
    value::value()
    {
        val_type = NONE;
        void_val = 0x00;
    }
    value::value( std::istream& stream )
    {
        
    }
    value::value( const value& original )
    {
        
    }
    
    value::~value()
    {
        clearCurrent();
    }
    
    void value::set( std::string string_val )
    {
        clearCurrent();
        
        
    }
    void value::set( long int_val )
    {
        clearCurrent();
        
        
    }
    void value::push( value& val )
    {
        if( val_type != LIST )
        {
            clearCurrent();
            val_type = LIST;
            list_val = new std::vector< value >;
        }
        
        list_val -> push_back( val );
    }
    void value::set( std::string key, value& val )
    {
        if( val_type != DICTIONARY )
        {
            clearCurrent();
            val_type = DICTIONARY;
            dict_val = new std::map< std::string, value >;
        }
        
        ( *dict_val )[ key ] = val;
    }
    
    value::type value::getType()
    {
        
    }
    
    std::string value::getString()
    {
        
    }
    long value::getInteger()
    {
        
    }
    std::pair< std::vector< value >::iterator,
               std::vector< value >::iterator > value::getList()
    {
        
    }
    std::pair< std::map< std::string, value >::iterator,
               std::map< std::string, value >::iterator > value::getDictionary()
    {
        
    }
    
    void value::serializeBencode( std::ostream& stream )
    {
        
    }
    void value::serializeJSON( std::ostream& stream )
    {
        
    }
    void value::serializeXML( std::ostream& stream )
    {
        
    }
    
    void value::clearCurrent()
    {
        switch( val_type )
        {
        case NONE:
        case INTEGER:
        default:
            // Nothing to delete
            break;
        case STRING:
            delete string_val;
            break;
        case LIST:
            delete list_val;
            break;
        case DICTIONARY:
            delete dict_val;
            break;
        }
        
        val_type = NONE;
    }
}


