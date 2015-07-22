#ifndef DEBENCODE_HPP
#define DEBENCODE_HPP

#include <iostream>
#include <string>
#include <vector>
#include <map>

namespace dbnc
{
    enum code
    {
        MALFORMED_INPUT,
        INPUT_ERROR,
        OUTPUT_ERROR,
        WRONG_TYPE,
        TYPE_MISMATCH
    };
    
    class value
    {
    public:
        enum type
        {
            STRING,
            INT,
            LIST,
            DICT
        };
        
        value();                                                                // Default constructor
        value( std::istream& );                                                 // Construct from an input stream
        value( const value& );                                                  // Copy constructor
        
        ~value();
        
        void set( std::string );                                                // Set the value's value to a string (clears any previous type)
        void set( long );                                                       // Set the value's value to an integer (clears any previous type)
        void push( value& );                                                    // Push a value into this as a list; if it is not already a list, clears any
                                                                                // previous type first
        void push( std::string, value& );                                       // Push a value into this as a dictionary with a string key; if it is not
                                                                                // already a dictionary, clears any previous type first
        
        std::string getString();                                                // Get the string value; throws dbnc::WRONG_TYPE if it is not a string
        long getInteger();                                                      // Get the integer value; throws dbnc::WRONG_TYPE if it is not an integer
        std::pair< std::vector< value >::iterator,
                   std::vector< value >::iterator > getList();                  // Get the begin & end iterators of the list value; throws dbnc::WRONG_TYPE if
                                                                                // it is not a list; behavior undefined if type changes while iterating
        std::pair< std::map< std::string, value >::iterator,
                   std::map< std::string, value >::iterator > getDictionary();  // Get the begin & end iterators of the dictionary value; throws
                                                                                // dbnc::WRONG_TYPE if it is not a dictionary; bahavior undefined if type
                                                                                // changes while iterating
        
        void serializeBencode( std::ostream& );                                 // Serialize the contents as Bencode to the supplied output stream
        void serializeJSON(    std::ostream& );                                 // Serialize the contents as JSON to the supplied output stream
        void serializeXML(     std::ostream& );                                 // Serialize the contents as XML to the supplied output stream
    protected:
        type type;
        union
        {
            std::string*                    string_val;
            long                            int_val;
            std::vector< value >*           list_val;
            std::map< std::string, value >* dict_val;
        };
    private:
    };
}

#endif


