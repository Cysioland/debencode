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
        clearCurrent();
    }
    value::value( std::istream& stream )
    {
        // IMPLEMENT: istream constructor
    }
    value::value( const value& original )
    {
        // IMPLEMENT: Copy constructor
    }
    
    value::~value()
    {
        clearCurrent();
    }
    
    void value::set( std::string string_val )
    {
        clearCurrent();
        
        val_type = STRING;
        this -> string_val = new std::string( string_val );
    }
    void value::set( long int_val )
    {
        clearCurrent();
        
        val_type = INTEGER;
        this -> int_val = int_val;
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
        return val_type;
    }
    
    std::string value::getString()
    {
        if( val_type != STRING )
            throw WRONG_TYPE;
        
        return *string_val;
    }
    long value::getInteger()
    {
        if( val_type != INTEGER )
            throw WRONG_TYPE;
        
        return int_val;
    }
    std::pair< std::vector< value >::iterator,
               std::vector< value >::iterator > value::getList()
    {
        if( val_type != LIST )
            throw WRONG_TYPE;
        
        return std::pair< std::vector< value >::iterator,
                          std::vector< value >::iterator >( list_val -> begin(),
                                                            list_val -> end() );
    }
    std::pair< std::map< std::string, value >::iterator,
               std::map< std::string, value >::iterator > value::getDictionary()
    {
        if( val_type != DICTIONARY )
            throw WRONG_TYPE;
        
        return std::pair< std::map< std::string, value >::iterator,
                          std::map< std::string, value >::iterator >( dict_val -> begin(),
                                                                      dict_val -> end() );
    }
    
    void value::serializeBencode( std::ostream& stream )
    {
        // IMPLEMENT: Bencode serializer
    }
    void value::serializeJSON( std::ostream& stream )
    {
        // IMPLEMENT: JSON serializer
    }
    void value::serializeXML( std::ostream& stream )
    {
        // IMPLEMENT: XML serializer
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
        void_val = 0x00;
    }
}


