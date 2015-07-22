#include "debencode.hpp"

namespace dbnc
{
    value::value()
    {
        val_type = NONE;
        void_val = 0x00;
    }
    value::value( std::istream& )
    {
        
    }
    value::value( const value& )
    {
        
    }
    
    value::~value()
    {
        clearCurrent();
    }
    
    void value::set( std::string )
    {
        clearCurrent();
        
        
    }
    void value::set( long )
    {
        clearCurrent();
        
        
    }
    void value::push( value& )
    {
        
    }
    void value::push( std::string, value& )
    {
        
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
    
    void value::serializeBencode( std::ostream& )
    {
        
    }
    void value::serializeJSON( std::ostream& )
    {
        
    }
    void value::serializeXML( std::ostream& )
    {
        
    }
    
    void value::clearCurrent()
    {
        switch( val_type )
        {
        case NONE:
        case INT:
        default:
            // Nothing to delete
            break;
        case STRING:
            delete string_val;
            break;
        case LIST:
            delete list_val;
            break;
        case DICT:
            delete dict_val;
            break;
        }
        
        val_type = NONE;
    }
}


