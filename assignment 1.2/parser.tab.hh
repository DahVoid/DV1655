// A Bison parser, made by GNU Bison 3.5.1.

// Skeleton interface for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.


/**
 ** \file parser.tab.hh
 ** Define the yy::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.

#ifndef YY_YY_PARSER_TAB_HH_INCLUDED
# define YY_YY_PARSER_TAB_HH_INCLUDED
// "%code requires" blocks.
#line 7 "parser.yy"

  #include <string>
  #include "Node.h"

#line 53 "parser.tab.hh"


# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif


#ifndef YY_ASSERT
# include <cassert>
# define YY_ASSERT assert
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

namespace yy {
#line 187 "parser.tab.hh"




  /// A Bison parser.
  class parser
  {
  public:
#ifndef YYSTYPE
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class semantic_type
  {
  public:
    /// Type of *this.
    typedef semantic_type self_type;

    /// Empty construction.
    semantic_type () YY_NOEXCEPT
      : yybuffer_ ()
    {}

    /// Construct and fill.
    template <typename T>
    semantic_type (YY_RVREF (T) t)
    {
      YY_ASSERT (sizeof (T) <= size);
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

    /// Destruction, allowed only if empty.
    ~semantic_type () YY_NOEXCEPT
    {}

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
    }

  private:
    /// Prohibit blind copies.
    self_type& operator= (const self_type&);
    semantic_type (const self_type&);

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yybuffer_.yyraw;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yybuffer_.yyraw;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // expression
      // otherExpression
      // boolExpression
      // funccallExpression
      // lengthExpression
      // indexExpression
      // logExpression
      // addExpression
      // multExpression
      // number
      // indentifier
      char dummy1[sizeof (Node *)];

      // INT
      // LP
      // RP
      // ESX
      // NEW
      // LB
      // RB
      // THIS
      // FALSE
      // TRUE
      // DOT
      // COMMA
      // LENGTH
      // SUB
      // MUL
      // DIV
      // PLUS
      // CMP
      // EQUAL
      // GT
      // LT
      // MT
      // OR
      // AND
      // COMMENT
      // SYSTEMOUTPRINT
      // WHILE
      // ELSE
      // LCB
      // RCB
      // BOOLEAN
      // RETURN
      // PUBLIC
      // EXTENDS
      // CLASS
      // STRING
      // MAIN
      // VOID
      // STATIC
      // SEMICOLON
      // NUM
      // WORD
      char dummy2[sizeof (std::string)];
    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me;
      /// A buffer large enough to store any of the semantic values.
      char yyraw[size];
    } yybuffer_;
  };

#else
    typedef YYSTYPE semantic_type;
#endif

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const std::string& m)
        : std::runtime_error (m)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;
    };

    /// Tokens.
    struct token
    {
      enum yytokentype
      {
        END = 0,
        INT = 258,
        LP = 259,
        RP = 260,
        ESX = 261,
        NEW = 262,
        LB = 263,
        RB = 264,
        THIS = 265,
        FALSE = 266,
        TRUE = 267,
        DOT = 268,
        COMMA = 269,
        LENGTH = 270,
        SUB = 271,
        MUL = 272,
        DIV = 273,
        PLUS = 274,
        CMP = 275,
        EQUAL = 276,
        GT = 277,
        LT = 278,
        MT = 279,
        OR = 280,
        AND = 281,
        COMMENT = 282,
        SYSTEMOUTPRINT = 283,
        WHILE = 284,
        ELSE = 285,
        LCB = 286,
        RCB = 287,
        BOOLEAN = 288,
        RETURN = 289,
        PUBLIC = 290,
        EXTENDS = 291,
        CLASS = 292,
        STRING = 293,
        MAIN = 294,
        VOID = 295,
        STATIC = 296,
        SEMICOLON = 297,
        NUM = 298,
        WORD = 299
      };
    };

    /// (External) token type, as returned by yylex.
    typedef token::yytokentype token_type;

    /// Symbol type: an internal symbol number.
    typedef int symbol_number_type;

    /// The symbol type number to denote an empty symbol.
    enum { empty_symbol = -2 };

    /// Internal symbol number for tokens (subsumed by symbol_number_type).
    typedef signed char token_number_type;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol type
    /// via type_get ().
    ///
    /// Provide access to semantic value.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol ()
        : value ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that);
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t)
        : Base (t)
      {}
#else
      basic_symbol (typename Base::kind_type t)
        : Base (t)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Node *&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Node *& v)
        : Base (t)
        , value (v)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::string&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::string& v)
        : Base (t)
        , value (v)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }

      /// Destroy contents, and record that is empty.
      void clear ()
      {
        // User destructor.
        symbol_number_type yytype = this->type_get ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yytype)
        {
       default:
          break;
        }

        // Type destructor.
switch (yytype)
    {
      case 46: // expression
      case 47: // otherExpression
      case 48: // boolExpression
      case 49: // funccallExpression
      case 50: // lengthExpression
      case 51: // indexExpression
      case 52: // logExpression
      case 53: // addExpression
      case 54: // multExpression
      case 55: // number
      case 56: // indentifier
        value.template destroy< Node * > ();
        break;

      case 3: // INT
      case 4: // LP
      case 5: // RP
      case 6: // ESX
      case 7: // NEW
      case 8: // LB
      case 9: // RB
      case 10: // THIS
      case 11: // FALSE
      case 12: // TRUE
      case 13: // DOT
      case 14: // COMMA
      case 15: // LENGTH
      case 16: // SUB
      case 17: // MUL
      case 18: // DIV
      case 19: // PLUS
      case 20: // CMP
      case 21: // EQUAL
      case 22: // GT
      case 23: // LT
      case 24: // MT
      case 25: // OR
      case 26: // AND
      case 27: // COMMENT
      case 28: // SYSTEMOUTPRINT
      case 29: // WHILE
      case 30: // ELSE
      case 31: // LCB
      case 32: // RCB
      case 33: // BOOLEAN
      case 34: // RETURN
      case 35: // PUBLIC
      case 36: // EXTENDS
      case 37: // CLASS
      case 38: // STRING
      case 39: // MAIN
      case 40: // VOID
      case 41: // STATIC
      case 42: // SEMICOLON
      case 43: // NUM
      case 44: // WORD
        value.template destroy< std::string > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      semantic_type value;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_type
    {
      /// Default constructor.
      by_type ();

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_type (by_type&& that);
#endif

      /// Copy constructor.
      by_type (const by_type& that);

      /// The symbol type as needed by the constructor.
      typedef token_type kind_type;

      /// Constructor from (external) token numbers.
      by_type (kind_type t);

      /// Record that this symbol is empty.
      void clear ();

      /// Steal the symbol type from \a that.
      void move (by_type& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_number_type type_get () const YY_NOEXCEPT;

      /// The symbol type.
      /// \a empty_symbol when empty.
      /// An int, not token_number_type, to be able to store empty_symbol.
      int type;
    };

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_type>
    {
      /// Superclass.
      typedef basic_symbol<by_type> super_type;

      /// Empty symbol.
      symbol_type () {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok)
        : super_type(token_type (tok))
      {
        YY_ASSERT (tok == token::END);
      }
#else
      symbol_type (int tok)
        : super_type(token_type (tok))
      {
        YY_ASSERT (tok == token::END);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::string v)
        : super_type(token_type (tok), std::move (v))
      {
        YY_ASSERT (tok == token::INT || tok == token::LP || tok == token::RP || tok == token::ESX || tok == token::NEW || tok == token::LB || tok == token::RB || tok == token::THIS || tok == token::FALSE || tok == token::TRUE || tok == token::DOT || tok == token::COMMA || tok == token::LENGTH || tok == token::SUB || tok == token::MUL || tok == token::DIV || tok == token::PLUS || tok == token::CMP || tok == token::EQUAL || tok == token::GT || tok == token::LT || tok == token::MT || tok == token::OR || tok == token::AND || tok == token::COMMENT || tok == token::SYSTEMOUTPRINT || tok == token::WHILE || tok == token::ELSE || tok == token::LCB || tok == token::RCB || tok == token::BOOLEAN || tok == token::RETURN || tok == token::PUBLIC || tok == token::EXTENDS || tok == token::CLASS || tok == token::STRING || tok == token::MAIN || tok == token::VOID || tok == token::STATIC || tok == token::SEMICOLON || tok == token::NUM || tok == token::WORD);
      }
#else
      symbol_type (int tok, const std::string& v)
        : super_type(token_type (tok), v)
      {
        YY_ASSERT (tok == token::INT || tok == token::LP || tok == token::RP || tok == token::ESX || tok == token::NEW || tok == token::LB || tok == token::RB || tok == token::THIS || tok == token::FALSE || tok == token::TRUE || tok == token::DOT || tok == token::COMMA || tok == token::LENGTH || tok == token::SUB || tok == token::MUL || tok == token::DIV || tok == token::PLUS || tok == token::CMP || tok == token::EQUAL || tok == token::GT || tok == token::LT || tok == token::MT || tok == token::OR || tok == token::AND || tok == token::COMMENT || tok == token::SYSTEMOUTPRINT || tok == token::WHILE || tok == token::ELSE || tok == token::LCB || tok == token::RCB || tok == token::BOOLEAN || tok == token::RETURN || tok == token::PUBLIC || tok == token::EXTENDS || tok == token::CLASS || tok == token::STRING || tok == token::MAIN || tok == token::VOID || tok == token::STATIC || tok == token::SEMICOLON || tok == token::NUM || tok == token::WORD);
      }
#endif
    };

    /// Build a parser object.
    parser ();
    virtual ~parser ();

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param msg    a description of the syntax error.
    virtual void error (const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

    // Implementation of make_symbol for each symbol type.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_END ()
      {
        return symbol_type (token::END);
      }
#else
      static
      symbol_type
      make_END ()
      {
        return symbol_type (token::END);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INT (std::string v)
      {
        return symbol_type (token::INT, std::move (v));
      }
#else
      static
      symbol_type
      make_INT (const std::string& v)
      {
        return symbol_type (token::INT, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LP (std::string v)
      {
        return symbol_type (token::LP, std::move (v));
      }
#else
      static
      symbol_type
      make_LP (const std::string& v)
      {
        return symbol_type (token::LP, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RP (std::string v)
      {
        return symbol_type (token::RP, std::move (v));
      }
#else
      static
      symbol_type
      make_RP (const std::string& v)
      {
        return symbol_type (token::RP, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ESX (std::string v)
      {
        return symbol_type (token::ESX, std::move (v));
      }
#else
      static
      symbol_type
      make_ESX (const std::string& v)
      {
        return symbol_type (token::ESX, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NEW (std::string v)
      {
        return symbol_type (token::NEW, std::move (v));
      }
#else
      static
      symbol_type
      make_NEW (const std::string& v)
      {
        return symbol_type (token::NEW, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LB (std::string v)
      {
        return symbol_type (token::LB, std::move (v));
      }
#else
      static
      symbol_type
      make_LB (const std::string& v)
      {
        return symbol_type (token::LB, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RB (std::string v)
      {
        return symbol_type (token::RB, std::move (v));
      }
#else
      static
      symbol_type
      make_RB (const std::string& v)
      {
        return symbol_type (token::RB, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_THIS (std::string v)
      {
        return symbol_type (token::THIS, std::move (v));
      }
#else
      static
      symbol_type
      make_THIS (const std::string& v)
      {
        return symbol_type (token::THIS, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FALSE (std::string v)
      {
        return symbol_type (token::FALSE, std::move (v));
      }
#else
      static
      symbol_type
      make_FALSE (const std::string& v)
      {
        return symbol_type (token::FALSE, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TRUE (std::string v)
      {
        return symbol_type (token::TRUE, std::move (v));
      }
#else
      static
      symbol_type
      make_TRUE (const std::string& v)
      {
        return symbol_type (token::TRUE, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DOT (std::string v)
      {
        return symbol_type (token::DOT, std::move (v));
      }
#else
      static
      symbol_type
      make_DOT (const std::string& v)
      {
        return symbol_type (token::DOT, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COMMA (std::string v)
      {
        return symbol_type (token::COMMA, std::move (v));
      }
#else
      static
      symbol_type
      make_COMMA (const std::string& v)
      {
        return symbol_type (token::COMMA, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LENGTH (std::string v)
      {
        return symbol_type (token::LENGTH, std::move (v));
      }
#else
      static
      symbol_type
      make_LENGTH (const std::string& v)
      {
        return symbol_type (token::LENGTH, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SUB (std::string v)
      {
        return symbol_type (token::SUB, std::move (v));
      }
#else
      static
      symbol_type
      make_SUB (const std::string& v)
      {
        return symbol_type (token::SUB, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MUL (std::string v)
      {
        return symbol_type (token::MUL, std::move (v));
      }
#else
      static
      symbol_type
      make_MUL (const std::string& v)
      {
        return symbol_type (token::MUL, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DIV (std::string v)
      {
        return symbol_type (token::DIV, std::move (v));
      }
#else
      static
      symbol_type
      make_DIV (const std::string& v)
      {
        return symbol_type (token::DIV, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PLUS (std::string v)
      {
        return symbol_type (token::PLUS, std::move (v));
      }
#else
      static
      symbol_type
      make_PLUS (const std::string& v)
      {
        return symbol_type (token::PLUS, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CMP (std::string v)
      {
        return symbol_type (token::CMP, std::move (v));
      }
#else
      static
      symbol_type
      make_CMP (const std::string& v)
      {
        return symbol_type (token::CMP, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EQUAL (std::string v)
      {
        return symbol_type (token::EQUAL, std::move (v));
      }
#else
      static
      symbol_type
      make_EQUAL (const std::string& v)
      {
        return symbol_type (token::EQUAL, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GT (std::string v)
      {
        return symbol_type (token::GT, std::move (v));
      }
#else
      static
      symbol_type
      make_GT (const std::string& v)
      {
        return symbol_type (token::GT, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LT (std::string v)
      {
        return symbol_type (token::LT, std::move (v));
      }
#else
      static
      symbol_type
      make_LT (const std::string& v)
      {
        return symbol_type (token::LT, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MT (std::string v)
      {
        return symbol_type (token::MT, std::move (v));
      }
#else
      static
      symbol_type
      make_MT (const std::string& v)
      {
        return symbol_type (token::MT, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OR (std::string v)
      {
        return symbol_type (token::OR, std::move (v));
      }
#else
      static
      symbol_type
      make_OR (const std::string& v)
      {
        return symbol_type (token::OR, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AND (std::string v)
      {
        return symbol_type (token::AND, std::move (v));
      }
#else
      static
      symbol_type
      make_AND (const std::string& v)
      {
        return symbol_type (token::AND, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COMMENT (std::string v)
      {
        return symbol_type (token::COMMENT, std::move (v));
      }
#else
      static
      symbol_type
      make_COMMENT (const std::string& v)
      {
        return symbol_type (token::COMMENT, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SYSTEMOUTPRINT (std::string v)
      {
        return symbol_type (token::SYSTEMOUTPRINT, std::move (v));
      }
#else
      static
      symbol_type
      make_SYSTEMOUTPRINT (const std::string& v)
      {
        return symbol_type (token::SYSTEMOUTPRINT, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_WHILE (std::string v)
      {
        return symbol_type (token::WHILE, std::move (v));
      }
#else
      static
      symbol_type
      make_WHILE (const std::string& v)
      {
        return symbol_type (token::WHILE, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ELSE (std::string v)
      {
        return symbol_type (token::ELSE, std::move (v));
      }
#else
      static
      symbol_type
      make_ELSE (const std::string& v)
      {
        return symbol_type (token::ELSE, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LCB (std::string v)
      {
        return symbol_type (token::LCB, std::move (v));
      }
#else
      static
      symbol_type
      make_LCB (const std::string& v)
      {
        return symbol_type (token::LCB, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RCB (std::string v)
      {
        return symbol_type (token::RCB, std::move (v));
      }
#else
      static
      symbol_type
      make_RCB (const std::string& v)
      {
        return symbol_type (token::RCB, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BOOLEAN (std::string v)
      {
        return symbol_type (token::BOOLEAN, std::move (v));
      }
#else
      static
      symbol_type
      make_BOOLEAN (const std::string& v)
      {
        return symbol_type (token::BOOLEAN, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RETURN (std::string v)
      {
        return symbol_type (token::RETURN, std::move (v));
      }
#else
      static
      symbol_type
      make_RETURN (const std::string& v)
      {
        return symbol_type (token::RETURN, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PUBLIC (std::string v)
      {
        return symbol_type (token::PUBLIC, std::move (v));
      }
#else
      static
      symbol_type
      make_PUBLIC (const std::string& v)
      {
        return symbol_type (token::PUBLIC, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EXTENDS (std::string v)
      {
        return symbol_type (token::EXTENDS, std::move (v));
      }
#else
      static
      symbol_type
      make_EXTENDS (const std::string& v)
      {
        return symbol_type (token::EXTENDS, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CLASS (std::string v)
      {
        return symbol_type (token::CLASS, std::move (v));
      }
#else
      static
      symbol_type
      make_CLASS (const std::string& v)
      {
        return symbol_type (token::CLASS, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STRING (std::string v)
      {
        return symbol_type (token::STRING, std::move (v));
      }
#else
      static
      symbol_type
      make_STRING (const std::string& v)
      {
        return symbol_type (token::STRING, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MAIN (std::string v)
      {
        return symbol_type (token::MAIN, std::move (v));
      }
#else
      static
      symbol_type
      make_MAIN (const std::string& v)
      {
        return symbol_type (token::MAIN, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VOID (std::string v)
      {
        return symbol_type (token::VOID, std::move (v));
      }
#else
      static
      symbol_type
      make_VOID (const std::string& v)
      {
        return symbol_type (token::VOID, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STATIC (std::string v)
      {
        return symbol_type (token::STATIC, std::move (v));
      }
#else
      static
      symbol_type
      make_STATIC (const std::string& v)
      {
        return symbol_type (token::STATIC, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SEMICOLON (std::string v)
      {
        return symbol_type (token::SEMICOLON, std::move (v));
      }
#else
      static
      symbol_type
      make_SEMICOLON (const std::string& v)
      {
        return symbol_type (token::SEMICOLON, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NUM (std::string v)
      {
        return symbol_type (token::NUM, std::move (v));
      }
#else
      static
      symbol_type
      make_NUM (const std::string& v)
      {
        return symbol_type (token::NUM, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_WORD (std::string v)
      {
        return symbol_type (token::WORD, std::move (v));
      }
#else
      static
      symbol_type
      make_WORD (const std::string& v)
      {
        return symbol_type (token::WORD, v);
      }
#endif


  private:
    /// This class is not copyable.
    parser (const parser&);
    parser& operator= (const parser&);

    /// Stored state numbers (used for stacks).
    typedef signed char state_type;

    /// Generate an error message.
    /// \param yystate   the state where the error occurred.
    /// \param yyla      the lookahead token.
    virtual std::string yysyntax_error_ (state_type yystate,
                                         const symbol_type& yyla) const;

    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    static state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue);

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue);

    static const signed char yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token number \a t to a symbol number.
    /// In theory \a t should be a token_type, but character literals
    /// are valid, yet not members of the token_type enum.
    static token_number_type yytranslate_ (int t);

    // Tables.
    // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const signed char yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const signed char yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const signed char yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const signed char yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const signed char yytable_[];

    static const signed char yycheck_[];

    // YYSTOS[STATE-NUM] -- The (internal number of the) accessing
    // symbol of state STATE-NUM.
    static const signed char yystos_[];

    // YYR1[YYN] -- Symbol number of symbol that rule YYN derives.
    static const signed char yyr1_[];

    // YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.
    static const signed char yyr2_[];


    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    static std::string yytnamerr_ (const char *n);


    /// For a symbol, its name in clear.
    static const char* const yytname_[];
#if YYDEBUG
    // YYRLINE[YYN] -- Source line where rule number YYN was defined.
    static const unsigned char yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r);
    /// Print the state stack on the debug stream.
    virtual void yystack_print_ ();

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol type, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol type as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol type from \a that.
      void move (by_state& that);

      /// The (internal) type number (corresponding to \a state).
      /// \a empty_symbol when empty.
      symbol_number_type type_get () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      /// We use the initial state, as it does not have a value.
      enum { empty_state = 0 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);

      /// Assignment, needed by push_back by other implementations.
      /// Needed by some other old implementations.
      stack_symbol_type& operator= (const stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::reverse_iterator iterator;
      typedef typename S::const_reverse_iterator const_iterator;
      typedef typename S::size_type size_type;
      typedef typename std::ptrdiff_t index_type;

      stack (size_type n = 200)
        : seq_ (n)
      {}

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (index_type i) const
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (index_type i)
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (std::ptrdiff_t n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      index_type
      size () const YY_NOEXCEPT
      {
        return index_type (seq_.size ());
      }

      std::ptrdiff_t
      ssize () const YY_NOEXCEPT
      {
        return std::ptrdiff_t (size ());
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.rbegin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.rend ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, index_type range)
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (index_type i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        index_type range_;
      };

    private:
      stack (const stack&);
      stack& operator= (const stack&);
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1);

    /// Some specific tokens.
    static const token_number_type yy_error_token_ = 1;
    static const token_number_type yy_undef_token_ = 2;

    /// Constants.
    enum
    {
      yyeof_ = 0,
      yylast_ = 133,     ///< Last index in yytable_.
      yynnts_ = 12,  ///< Number of nonterminal symbols.
      yyfinal_ = 24, ///< Termination state number.
      yyntokens_ = 45  ///< Number of tokens.
    };


  };

  inline
  parser::token_number_type
  parser::yytranslate_ (int t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const token_number_type
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
    };
    const int user_token_number_max_ = 299;

    if (t <= 0)
      return yyeof_;
    else if (t <= user_token_number_max_)
      return translate_table[t];
    else
      return yy_undef_token_;
  }

  // basic_symbol.
#if 201103L <= YY_CPLUSPLUS
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (basic_symbol&& that)
    : Base (std::move (that))
    , value ()
  {
    switch (this->type_get ())
    {
      case 46: // expression
      case 47: // otherExpression
      case 48: // boolExpression
      case 49: // funccallExpression
      case 50: // lengthExpression
      case 51: // indexExpression
      case 52: // logExpression
      case 53: // addExpression
      case 54: // multExpression
      case 55: // number
      case 56: // indentifier
        value.move< Node * > (std::move (that.value));
        break;

      case 3: // INT
      case 4: // LP
      case 5: // RP
      case 6: // ESX
      case 7: // NEW
      case 8: // LB
      case 9: // RB
      case 10: // THIS
      case 11: // FALSE
      case 12: // TRUE
      case 13: // DOT
      case 14: // COMMA
      case 15: // LENGTH
      case 16: // SUB
      case 17: // MUL
      case 18: // DIV
      case 19: // PLUS
      case 20: // CMP
      case 21: // EQUAL
      case 22: // GT
      case 23: // LT
      case 24: // MT
      case 25: // OR
      case 26: // AND
      case 27: // COMMENT
      case 28: // SYSTEMOUTPRINT
      case 29: // WHILE
      case 30: // ELSE
      case 31: // LCB
      case 32: // RCB
      case 33: // BOOLEAN
      case 34: // RETURN
      case 35: // PUBLIC
      case 36: // EXTENDS
      case 37: // CLASS
      case 38: // STRING
      case 39: // MAIN
      case 40: // VOID
      case 41: // STATIC
      case 42: // SEMICOLON
      case 43: // NUM
      case 44: // WORD
        value.move< std::string > (std::move (that.value));
        break;

      default:
        break;
    }

  }
#endif

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
  {
    switch (this->type_get ())
    {
      case 46: // expression
      case 47: // otherExpression
      case 48: // boolExpression
      case 49: // funccallExpression
      case 50: // lengthExpression
      case 51: // indexExpression
      case 52: // logExpression
      case 53: // addExpression
      case 54: // multExpression
      case 55: // number
      case 56: // indentifier
        value.copy< Node * > (YY_MOVE (that.value));
        break;

      case 3: // INT
      case 4: // LP
      case 5: // RP
      case 6: // ESX
      case 7: // NEW
      case 8: // LB
      case 9: // RB
      case 10: // THIS
      case 11: // FALSE
      case 12: // TRUE
      case 13: // DOT
      case 14: // COMMA
      case 15: // LENGTH
      case 16: // SUB
      case 17: // MUL
      case 18: // DIV
      case 19: // PLUS
      case 20: // CMP
      case 21: // EQUAL
      case 22: // GT
      case 23: // LT
      case 24: // MT
      case 25: // OR
      case 26: // AND
      case 27: // COMMENT
      case 28: // SYSTEMOUTPRINT
      case 29: // WHILE
      case 30: // ELSE
      case 31: // LCB
      case 32: // RCB
      case 33: // BOOLEAN
      case 34: // RETURN
      case 35: // PUBLIC
      case 36: // EXTENDS
      case 37: // CLASS
      case 38: // STRING
      case 39: // MAIN
      case 40: // VOID
      case 41: // STATIC
      case 42: // SEMICOLON
      case 43: // NUM
      case 44: // WORD
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }



  template <typename Base>
  bool
  parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->type_get ())
    {
      case 46: // expression
      case 47: // otherExpression
      case 48: // boolExpression
      case 49: // funccallExpression
      case 50: // lengthExpression
      case 51: // indexExpression
      case 52: // logExpression
      case 53: // addExpression
      case 54: // multExpression
      case 55: // number
      case 56: // indentifier
        value.move< Node * > (YY_MOVE (s.value));
        break;

      case 3: // INT
      case 4: // LP
      case 5: // RP
      case 6: // ESX
      case 7: // NEW
      case 8: // LB
      case 9: // RB
      case 10: // THIS
      case 11: // FALSE
      case 12: // TRUE
      case 13: // DOT
      case 14: // COMMA
      case 15: // LENGTH
      case 16: // SUB
      case 17: // MUL
      case 18: // DIV
      case 19: // PLUS
      case 20: // CMP
      case 21: // EQUAL
      case 22: // GT
      case 23: // LT
      case 24: // MT
      case 25: // OR
      case 26: // AND
      case 27: // COMMENT
      case 28: // SYSTEMOUTPRINT
      case 29: // WHILE
      case 30: // ELSE
      case 31: // LCB
      case 32: // RCB
      case 33: // BOOLEAN
      case 34: // RETURN
      case 35: // PUBLIC
      case 36: // EXTENDS
      case 37: // CLASS
      case 38: // STRING
      case 39: // MAIN
      case 40: // VOID
      case 41: // STATIC
      case 42: // SEMICOLON
      case 43: // NUM
      case 44: // WORD
        value.move< std::string > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

  }

  // by_type.
  inline
  parser::by_type::by_type ()
    : type (empty_symbol)
  {}

#if 201103L <= YY_CPLUSPLUS
  inline
  parser::by_type::by_type (by_type&& that)
    : type (that.type)
  {
    that.clear ();
  }
#endif

  inline
  parser::by_type::by_type (const by_type& that)
    : type (that.type)
  {}

  inline
  parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  inline
  void
  parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  inline
  int
  parser::by_type::type_get () const YY_NOEXCEPT
  {
    return type;
  }

} // yy
#line 2078 "parser.tab.hh"





#endif // !YY_YY_PARSER_TAB_HH_INCLUDED
