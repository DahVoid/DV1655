// A Bison parser, made by GNU Bison 3.5.1.

// Skeleton implementation for Bison LALR(1) parsers in C++

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

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.





#include "parser.tab.hh"


// Unqualified %code blocks.
#line 12 "parser.yy"

  #define YY_DECL yy::parser::symbol_type yylex()

  YY_DECL;
  
  Node* root;
  

#line 54 "parser.tab.cc"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif



// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 126 "parser.tab.cc"


  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr)
#else

#endif
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_number_type
  parser::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[+state];
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state))
  {
    switch (that.type_get ())
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
        value.YY_MOVE_OR_COPY< Node * > (YY_MOVE (that.value));
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
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s)
  {
    switch (that.type_get ())
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
        value.move< Node * > (YY_MOVE (that.value));
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
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
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
        value.copy< Node * > (that.value);
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
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
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
        value.move< Node * > (that.value);
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
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
#if defined __GNUC__ && ! defined __clang__ && ! defined __ICC && __GNUC__ * 100 + __GNUC_MINOR__ <= 408
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
#endif
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " (";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex ());
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
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
        yylhs.value.emplace< Node * > ();
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
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }



      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2:
#line 27 "parser.yy"
                          {yylhs.value.as < Node * > () = new Node("Expression", "");
                          yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                          root = yylhs.value.as < Node * > ();
                          }
#line 838 "parser.tab.cc"
    break;

  case 3:
#line 31 "parser.yy"
                          {yylhs.value.as < Node * > () = new Node("Expression", "");
                          yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                          root = yylhs.value.as < Node * > ();
                          }
#line 847 "parser.tab.cc"
    break;

  case 4:
#line 35 "parser.yy"
                            {yylhs.value.as < Node * > () = new Node("Expression", "");
                          yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                          root = yylhs.value.as < Node * > ();
                          }
#line 856 "parser.tab.cc"
    break;

  case 5:
#line 39 "parser.yy"
                             {yylhs.value.as < Node * > () = new Node("Expression", "");
                          yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                          root = yylhs.value.as < Node * > ();
                          }
#line 865 "parser.tab.cc"
    break;

  case 6:
#line 43 "parser.yy"
                               {yylhs.value.as < Node * > () = new Node("Expression", "");
                          yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                          root = yylhs.value.as < Node * > ();
                          }
#line 874 "parser.tab.cc"
    break;

  case 7:
#line 47 "parser.yy"
                           {yylhs.value.as < Node * > () = new Node("Expression", "");
                          yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                          root = yylhs.value.as < Node * > ();
                          }
#line 883 "parser.tab.cc"
    break;

  case 8:
#line 51 "parser.yy"
                        {yylhs.value.as < Node * > () = new Node("Expression", "");
                          yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                          root = yylhs.value.as < Node * > ();
                          }
#line 892 "parser.tab.cc"
    break;

  case 9:
#line 55 "parser.yy"
                            {yylhs.value.as < Node * > () = new Node("Expression", "");
                          yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                          root = yylhs.value.as < Node * > ();
                          }
#line 901 "parser.tab.cc"
    break;

  case 11:
#line 61 "parser.yy"
                                          {yylhs.value.as < Node * > () = new Node("otherExpression", "");
                                                 yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                                                 }
#line 909 "parser.tab.cc"
    break;

  case 12:
#line 64 "parser.yy"
                                       {yylhs.value.as < Node * > () = new Node("otherExpression", "");
                                                 yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                                 }
#line 917 "parser.tab.cc"
    break;

  case 13:
#line 67 "parser.yy"
                                {yylhs.value.as < Node * > () = new Node("otherExpression", "");
                                                 yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                                 }
#line 925 "parser.tab.cc"
    break;

  case 14:
#line 70 "parser.yy"
                                  {yylhs.value.as < Node * > () = new Node("otherExpression", "");
                                                 yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                                                 }
#line 933 "parser.tab.cc"
    break;

  case 15:
#line 74 "parser.yy"
                     {yylhs.value.as < Node * > () = new Node("boolExpression", yystack_[0].value.as < std::string > ());}
#line 939 "parser.tab.cc"
    break;

  case 16:
#line 75 "parser.yy"
                      {yylhs.value.as < Node * > () = new Node("boolExpression", yystack_[0].value.as < std::string > ());}
#line 945 "parser.tab.cc"
    break;

  case 17:
#line 77 "parser.yy"
                                                                                 {yylhs.value.as < Node * > () = new Node("funccallExpression", "");
                                                 yylhs.value.as < Node * > ()->children.push_back(yystack_[7].value.as < Node * > ());
                                                 yylhs.value.as < Node * > ()->children.push_back(yystack_[5].value.as < Node * > ());
                                                 yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
                                                 yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                                                 }
#line 956 "parser.tab.cc"
    break;

  case 18:
#line 84 "parser.yy"
                                        {yylhs.value.as < Node * > () = new Node("lengthExpression", "");
                                                 yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                                 }
#line 964 "parser.tab.cc"
    break;

  case 19:
#line 89 "parser.yy"
                                             {yylhs.value.as < Node * > () = new Node("indexExpression", "");
                                                 yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
                                                 yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                                                 }
#line 973 "parser.tab.cc"
    break;

  case 20:
#line 94 "parser.yy"
                                        {yylhs.value.as < Node * > () = new Node("logExpression", "");
                                                 yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                                 yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                                 }
#line 982 "parser.tab.cc"
    break;

  case 21:
#line 98 "parser.yy"
                                         {yylhs.value.as < Node * > () = new Node("logExpression", "");
                                                 yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                                 yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                                 }
#line 991 "parser.tab.cc"
    break;

  case 22:
#line 102 "parser.yy"
                                         {yylhs.value.as < Node * > () = new Node("logExpression", "");
                                                 yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                                 yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                                 }
#line 1000 "parser.tab.cc"
    break;

  case 23:
#line 106 "parser.yy"
                                        {yylhs.value.as < Node * > () = new Node("logExpression", "");
                                                 yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                                 yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                                 }
#line 1009 "parser.tab.cc"
    break;

  case 24:
#line 110 "parser.yy"
                                        {yylhs.value.as < Node * > () = new Node("logExpression", "");
                                                 yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                                 yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                                 }
#line 1018 "parser.tab.cc"
    break;

  case 25:
#line 115 "parser.yy"
                              {yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();}
#line 1024 "parser.tab.cc"
    break;

  case 26:
#line 116 "parser.yy"
                                                {yylhs.value.as < Node * > () = new Node("AddExpression", "");
                                                 yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                                 yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                                 }
#line 1033 "parser.tab.cc"
    break;

  case 27:
#line 121 "parser.yy"
                                                 {yylhs.value.as < Node * > () = new Node("SubExpression", "");
                                                 yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                                 yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                                 }
#line 1042 "parser.tab.cc"
    break;

  case 28:
#line 126 "parser.yy"
                       {yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();}
#line 1048 "parser.tab.cc"
    break;

  case 29:
#line 127 "parser.yy"
                                         {yylhs.value.as < Node * > () = new Node("MultExpression", "");
                                          yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                          yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                          }
#line 1057 "parser.tab.cc"
    break;

  case 30:
#line 132 "parser.yy"
                                         {yylhs.value.as < Node * > () = new Node("DivExpression", "");
                                          yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                          yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                          }
#line 1066 "parser.tab.cc"
    break;

  case 31:
#line 137 "parser.yy"
            {yylhs.value.as < Node * > () = new Node("NUM", yystack_[0].value.as < std::string > ());}
#line 1072 "parser.tab.cc"
    break;

  case 32:
#line 138 "parser.yy"
                         {yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();}
#line 1078 "parser.tab.cc"
    break;

  case 33:
#line 140 "parser.yy"
                  {yylhs.value.as < Node * > () = new Node("indentifier", yystack_[0].value.as < std::string > ());}
#line 1084 "parser.tab.cc"
    break;


#line 1088 "parser.tab.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yysyntax_error_ (yystack_[0].state, yyla));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[+yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yy_error_token_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yy_error_token_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }


      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    std::ptrdiff_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */
    if (!yyla.empty ())
      {
        symbol_number_type yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];

        int yyn = yypact_[+yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yy_error_token_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -16;

  const signed char parser::yytable_ninf_ = -33;

  const signed char
  parser::yypact_[] =
  {
      -2,    -2,    -2,     0,   -16,   -16,   -16,   -16,   -16,    12,
     -16,   -16,   -16,   -16,   -16,   -16,     3,    -3,   -16,   -16,
      42,    83,     5,    17,   -16,    -2,    -4,    -2,    -2,    -2,
      -2,    -2,     2,     2,     2,     2,   106,    -2,    18,    72,
     -16,    27,    83,    83,    83,    83,    83,    -2,    -3,    -3,
     -16,   -16,    91,   -16,   -16,    -2,    53,   -16,   107,   -16,
      -2,    64,   -16
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     0,    10,    16,    15,    31,    33,     0,
       9,     7,     6,     5,     4,     3,     2,    25,    28,     8,
       0,    13,     0,     0,     1,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    14,     0,     0,     0,
      18,     0,    22,    23,    24,    20,    21,     0,    27,    26,
      29,    30,     0,    12,    19,     0,     0,    11,     0,    32,
       0,     0,    17
  };

  const signed char
  parser::yypgoto_[] =
  {
     -16,    -1,   -16,   -16,   -16,   -16,   -16,   -16,   -16,   -15,
      14,    13
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19
  };

  const signed char
  parser::yytable_[] =
  {
      20,    21,     1,    22,     2,     3,    47,     0,     4,     5,
       6,    40,    24,    37,    34,    35,    23,    48,    49,    32,
      25,    38,    33,    53,    39,    26,    42,    43,    44,    45,
      46,    55,    27,     0,    28,    29,    52,    30,    31,    41,
       8,     7,     8,     0,     8,     7,    56,    36,    50,    51,
      25,     0,     0,     0,    58,    26,     0,     0,    59,    61,
       0,    25,    27,     0,    28,    29,    26,    30,    31,    62,
       0,     0,    25,    27,     0,    28,    29,    26,    30,    31,
      25,    54,     0,     0,    27,    26,    28,    29,     0,    30,
      31,    25,    27,     0,    28,    29,    26,    30,    31,    25,
      57,     0,     0,    27,    26,    28,    29,     0,    30,    31,
       0,    27,     0,    28,    29,    25,    30,    31,     0,     0,
      26,    60,   -32,   -32,   -32,   -32,     0,    27,     0,    28,
      29,     0,    30,    31
  };

  const signed char
  parser::yycheck_[] =
  {
       1,     2,     4,     3,     6,     7,     4,    -1,    10,    11,
      12,    15,     0,     8,    17,    18,     3,    32,    33,    16,
       8,     4,    19,     5,    25,    13,    27,    28,    29,    30,
      31,     4,    20,    -1,    22,    23,    37,    25,    26,    26,
      44,    43,    44,    -1,    44,    43,    47,     5,    34,    35,
       8,    -1,    -1,    -1,    55,    13,    -1,    -1,     5,    60,
      -1,     8,    20,    -1,    22,    23,    13,    25,    26,     5,
      -1,    -1,     8,    20,    -1,    22,    23,    13,    25,    26,
       8,     9,    -1,    -1,    20,    13,    22,    23,    -1,    25,
      26,     8,    20,    -1,    22,    23,    13,    25,    26,     8,
       9,    -1,    -1,    20,    13,    22,    23,    -1,    25,    26,
      -1,    20,    -1,    22,    23,     8,    25,    26,    -1,    -1,
      13,    14,    16,    17,    18,    19,    -1,    20,    -1,    22,
      23,    -1,    25,    26
  };

  const signed char
  parser::yystos_[] =
  {
       0,     4,     6,     7,    10,    11,    12,    43,    44,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      46,    46,     3,    56,     0,     8,    13,    20,    22,    23,
      25,    26,    16,    19,    17,    18,     5,     8,     4,    46,
      15,    56,    46,    46,    46,    46,    46,     4,    54,    54,
      55,    55,    46,     5,     9,     4,    46,     9,    46,     5,
      14,    46,     5
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    45,    46,    46,    46,    46,    46,    46,    46,    46,
      47,    47,    47,    47,    47,    48,    48,    49,    50,    51,
      52,    52,    52,    52,    52,    53,    53,    53,    54,    54,
      54,    55,    55,    56
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     5,     4,     2,     3,     1,     1,     8,     3,     4,
       3,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     1,     3,     1
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "INT", "LP", "RP", "ESX",
  "NEW", "LB", "RB", "THIS", "FALSE", "TRUE", "DOT", "COMMA", "LENGTH",
  "SUB", "MUL", "DIV", "PLUS", "CMP", "EQUAL", "GT", "LT", "MT", "OR",
  "AND", "COMMENT", "SYSTEMOUTPRINT", "WHILE", "ELSE", "LCB", "RCB",
  "BOOLEAN", "RETURN", "PUBLIC", "EXTENDS", "CLASS", "STRING", "MAIN",
  "VOID", "STATIC", "SEMICOLON", "NUM", "WORD", "$accept", "expression",
  "otherExpression", "boolExpression", "funccallExpression",
  "lengthExpression", "indexExpression", "logExpression", "addExpression",
  "multExpression", "number", "indentifier", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned char
  parser::yyrline_[] =
  {
       0,    27,    27,    31,    35,    39,    43,    47,    51,    55,
      60,    61,    64,    67,    70,    74,    75,    77,    84,    89,
      94,    98,   102,   106,   110,   115,   116,   121,   126,   127,
     132,   137,   138,   140
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


} // yy
#line 1524 "parser.tab.cc"

