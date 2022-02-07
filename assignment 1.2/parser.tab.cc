// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015 Free Software Foundation, Inc.

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


// First part of user declarations.

#line 37 "parser.tab.cc" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "parser.tab.hh"

// User implementation prologue.

#line 51 "parser.tab.cc" // lalr1.cc:412
// Unqualified %code blocks.
#line 13 "parser.yy" // lalr1.cc:413

  #define YY_DECL yy::parser::symbol_type yylex()

  YY_DECL;

  Node* root;


#line 62 "parser.tab.cc" // lalr1.cc:413


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



// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

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
      *yycdebug_ << std::endl;                  \
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
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace yy {
#line 129 "parser.tab.cc" // lalr1.cc:479

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
        std::string yyr = "";
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
              // Fall through.
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
     :yydebug_ (false),
      yycdebug_ (&std::cerr)
#endif
  {}

  parser::~parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  inline
  parser::by_state::by_state ()
    : state (empty_state)
  {}

  inline
  parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  parser::by_state::clear ()
  {
    state = empty_state;
  }

  inline
  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  inline
  parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  parser::symbol_number_type
  parser::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  inline
  parser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s)
  {
      switch (that.type_get ())
    {
      case 47: // goal
      case 48: // mainclass
      case 49: // classdeclaration
      case 50: // vardeclaration
      case 51: // methoddeclaration
      case 52: // type
      case 53: // statement
      case 54: // expression
      case 55: // OR_expression
      case 56: // AND_expression
      case 57: // EQUALITY_expression
      case 58: // REL_expression
      case 59: // addExpression
      case 60: // multExpression
      case 61: // negation_expression
      case 62: // par_expression
      case 63: // vardeclaration_rep
      case 64: // classdeclaration_rep
      case 65: // statement_rep
      case 66: // methoddeclaration_rep
      case 67: // parameterdeclaration_rep
      case 68: // argdeclaration_rep
      case 69: // identifier
      case 70: // number
        value.move< Node * > (that.value);
        break;

      case 3: // IF
      case 4: // INT
      case 5: // LP
      case 6: // RP
      case 7: // ESX
      case 8: // NEW
      case 9: // LB
      case 10: // RB
      case 11: // THIS
      case 12: // FALSE
      case 13: // TRUE
      case 14: // DOT
      case 15: // COMMA
      case 16: // LENGTH
      case 17: // SUB
      case 18: // MUL
      case 19: // DIV
      case 20: // PLUS
      case 21: // CMP
      case 22: // EQUAL
      case 23: // GT
      case 24: // LT
      case 25: // MT
      case 26: // OR
      case 27: // AND
      case 28: // COMMENT
      case 29: // SYSTEMOUTPRINT
      case 30: // WHILE
      case 31: // ELSE
      case 32: // LCB
      case 33: // RCB
      case 34: // BOOLEAN
      case 35: // RETURN
      case 36: // PUBLIC
      case 37: // EXTENDS
      case 38: // CLASS
      case 39: // STRING
      case 40: // MAIN
      case 41: // VOID
      case 42: // STATIC
      case 43: // SEMICOLON
      case 44: // NUM
      case 45: // WORD
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

  inline
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
      switch (that.type_get ())
    {
      case 47: // goal
      case 48: // mainclass
      case 49: // classdeclaration
      case 50: // vardeclaration
      case 51: // methoddeclaration
      case 52: // type
      case 53: // statement
      case 54: // expression
      case 55: // OR_expression
      case 56: // AND_expression
      case 57: // EQUALITY_expression
      case 58: // REL_expression
      case 59: // addExpression
      case 60: // multExpression
      case 61: // negation_expression
      case 62: // par_expression
      case 63: // vardeclaration_rep
      case 64: // classdeclaration_rep
      case 65: // statement_rep
      case 66: // methoddeclaration_rep
      case 67: // parameterdeclaration_rep
      case 68: // argdeclaration_rep
      case 69: // identifier
      case 70: // number
        value.copy< Node * > (that.value);
        break;

      case 3: // IF
      case 4: // INT
      case 5: // LP
      case 6: // RP
      case 7: // ESX
      case 8: // NEW
      case 9: // LB
      case 10: // RB
      case 11: // THIS
      case 12: // FALSE
      case 13: // TRUE
      case 14: // DOT
      case 15: // COMMA
      case 16: // LENGTH
      case 17: // SUB
      case 18: // MUL
      case 19: // DIV
      case 20: // PLUS
      case 21: // CMP
      case 22: // EQUAL
      case 23: // GT
      case 24: // LT
      case 25: // MT
      case 26: // OR
      case 27: // AND
      case 28: // COMMENT
      case 29: // SYSTEMOUTPRINT
      case 30: // WHILE
      case 31: // ELSE
      case 32: // LCB
      case 33: // RCB
      case 34: // BOOLEAN
      case 35: // RETURN
      case 36: // PUBLIC
      case 37: // EXTENDS
      case 38: // CLASS
      case 39: // STRING
      case 40: // MAIN
      case 41: // VOID
      case 42: // STATIC
      case 43: // SEMICOLON
      case 44: // NUM
      case 45: // WORD
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }


  template <typename Base>
  inline
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
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " (";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  inline
  void
  parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  parser::yypop_ (unsigned int n)
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

  inline parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::parse ()
  {
    // State.
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

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            symbol_type yylookahead (yylex ());
            yyla.move (yylookahead);
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

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
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
        switch (yyr1_[yyn])
    {
      case 47: // goal
      case 48: // mainclass
      case 49: // classdeclaration
      case 50: // vardeclaration
      case 51: // methoddeclaration
      case 52: // type
      case 53: // statement
      case 54: // expression
      case 55: // OR_expression
      case 56: // AND_expression
      case 57: // EQUALITY_expression
      case 58: // REL_expression
      case 59: // addExpression
      case 60: // multExpression
      case 61: // negation_expression
      case 62: // par_expression
      case 63: // vardeclaration_rep
      case 64: // classdeclaration_rep
      case 65: // statement_rep
      case 66: // methoddeclaration_rep
      case 67: // parameterdeclaration_rep
      case 68: // argdeclaration_rep
      case 69: // identifier
      case 70: // number
        yylhs.value.build< Node * > ();
        break;

      case 3: // IF
      case 4: // INT
      case 5: // LP
      case 6: // RP
      case 7: // ESX
      case 8: // NEW
      case 9: // LB
      case 10: // RB
      case 11: // THIS
      case 12: // FALSE
      case 13: // TRUE
      case 14: // DOT
      case 15: // COMMA
      case 16: // LENGTH
      case 17: // SUB
      case 18: // MUL
      case 19: // DIV
      case 20: // PLUS
      case 21: // CMP
      case 22: // EQUAL
      case 23: // GT
      case 24: // LT
      case 25: // MT
      case 26: // OR
      case 27: // AND
      case 28: // COMMENT
      case 29: // SYSTEMOUTPRINT
      case 30: // WHILE
      case 31: // ELSE
      case 32: // LCB
      case 33: // RCB
      case 34: // BOOLEAN
      case 35: // RETURN
      case 36: // PUBLIC
      case 37: // EXTENDS
      case 38: // CLASS
      case 39: // STRING
      case 40: // MAIN
      case 41: // VOID
      case 42: // STATIC
      case 43: // SEMICOLON
      case 44: // NUM
      case 45: // WORD
        yylhs.value.build< std::string > ();
        break;

      default:
        break;
    }



      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 2:
#line 28 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("Goal", "");
                          yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ());
                          yylhs.value.as< Node * > ()->children.push_back(yystack_[1].value.as< Node * > ());
                          root = yylhs.value.as< Node * > ();
                          }
#line 715 "parser.tab.cc" // lalr1.cc:859
    break;

  case 3:
#line 34 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("MainClass", "");
                          yylhs.value.as< Node * > ()->children.push_back(yystack_[15].value.as< Node * > ());
                          yylhs.value.as< Node * > ()->children.push_back(yystack_[5].value.as< Node * > ());
                          yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ());
                          }
#line 725 "parser.tab.cc" // lalr1.cc:859
    break;

  case 4:
#line 40 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("ClassDeclaration", "");
                          yylhs.value.as< Node * > ()->children.push_back(yystack_[4].value.as< Node * > ());
                          yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ());
                          yylhs.value.as< Node * > ()->children.push_back(yystack_[1].value.as< Node * > ());
                          }
#line 735 "parser.tab.cc" // lalr1.cc:859
    break;

  case 5:
#line 45 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("ClassDeclaration", "");
                                          yylhs.value.as< Node * > ()->children.push_back(yystack_[6].value.as< Node * > ());
                                          yylhs.value.as< Node * > ()->children.push_back(yystack_[4].value.as< Node * > ());
                                          yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ());
                                          yylhs.value.as< Node * > ()->children.push_back(yystack_[1].value.as< Node * > ());
                                          }
#line 746 "parser.tab.cc" // lalr1.cc:859
    break;

  case 6:
#line 52 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("VarDeclaration", "");
                          yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ());
                          yylhs.value.as< Node * > ()->children.push_back(yystack_[1].value.as< Node * > ());
                          }
#line 755 "parser.tab.cc" // lalr1.cc:859
    break;

  case 7:
#line 57 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("MethodDeclaration", "");
                          yylhs.value.as< Node * > ()->children.push_back(yystack_[10].value.as< Node * > ());
                          yylhs.value.as< Node * > ()->children.push_back(yystack_[9].value.as< Node * > ());
                          yylhs.value.as< Node * > ()->children.push_back(yystack_[5].value.as< Node * > ());
                          yylhs.value.as< Node * > ()->children.push_back(yystack_[4].value.as< Node * > ());
                          yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ());
                          }
#line 767 "parser.tab.cc" // lalr1.cc:859
    break;

  case 8:
#line 64 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("MethodDeclaration", "");
                                           yylhs.value.as< Node * > ()->children.push_back(yystack_[11].value.as< Node * > ());
                                           yylhs.value.as< Node * > ()->children.push_back(yystack_[10].value.as< Node * > ());
                                           yylhs.value.as< Node * > ()->children.push_back(yystack_[8].value.as< Node * > ());
                                           yylhs.value.as< Node * > ()->children.push_back(yystack_[5].value.as< Node * > ());
                                           yylhs.value.as< Node * > ()->children.push_back(yystack_[4].value.as< Node * > ());
                                           yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ());
                                           }
#line 780 "parser.tab.cc" // lalr1.cc:859
    break;

  case 9:
#line 73 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("Type", "");
                          }
#line 787 "parser.tab.cc" // lalr1.cc:859
    break;

  case 10:
#line 75 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("Type", "");
                          }
#line 794 "parser.tab.cc" // lalr1.cc:859
    break;

  case 11:
#line 77 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("Type", "");
                          }
#line 801 "parser.tab.cc" // lalr1.cc:859
    break;

  case 12:
#line 79 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("Type", "");
                          yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());
                          }
#line 809 "parser.tab.cc" // lalr1.cc:859
    break;

  case 13:
#line 83 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("PARAMETER","");
                          yylhs.value.as< Node * > ()->children.push_back(yystack_[1].value.as< Node * > ());
                          }
#line 817 "parser.tab.cc" // lalr1.cc:859
    break;

  case 14:
#line 87 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("IF","");
                          yylhs.value.as< Node * > ()->children.push_back(yystack_[4].value.as< Node * > ());
                          yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ());
                          yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());
                          }
#line 827 "parser.tab.cc" // lalr1.cc:859
    break;

  case 15:
#line 92 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("WHILE","");
                          yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ());
                          yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());
                          }
#line 836 "parser.tab.cc" // lalr1.cc:859
    break;

  case 16:
#line 96 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("SYSTEMOUTPRINT","");
                          yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ());
                          }
#line 844 "parser.tab.cc" // lalr1.cc:859
    break;

  case 17:
#line 99 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("EQUAL","");
                          yylhs.value.as< Node * > ()->children.push_back(yystack_[3].value.as< Node * > ());
                          yylhs.value.as< Node * > ()->children.push_back(yystack_[1].value.as< Node * > ());
                          }
#line 853 "parser.tab.cc" // lalr1.cc:859
    break;

  case 18:
#line 103 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("INDEX EQUAL TO","");
                          yylhs.value.as< Node * > ()->children.push_back(yystack_[6].value.as< Node * > ());
                          yylhs.value.as< Node * > ()->children.push_back(yystack_[4].value.as< Node * > ());
                          yylhs.value.as< Node * > ()->children.push_back(yystack_[1].value.as< Node * > ());
                          }
#line 863 "parser.tab.cc" // lalr1.cc:859
    break;

  case 19:
#line 109 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = yystack_[0].value.as< Node * > ();}
#line 869 "parser.tab.cc" // lalr1.cc:859
    break;

  case 20:
#line 110 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("boolExpression", yystack_[0].value.as< std::string > ());}
#line 875 "parser.tab.cc" // lalr1.cc:859
    break;

  case 21:
#line 111 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("boolExpression", yystack_[0].value.as< std::string > ());}
#line 881 "parser.tab.cc" // lalr1.cc:859
    break;

  case 22:
#line 112 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("OtherExpression", yystack_[0].value.as< std::string > ());}
#line 887 "parser.tab.cc" // lalr1.cc:859
    break;

  case 23:
#line 113 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("OtherExpression", yystack_[3].value.as< std::string > ());}
#line 893 "parser.tab.cc" // lalr1.cc:859
    break;

  case 24:
#line 115 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = yystack_[0].value.as< Node * > ();}
#line 899 "parser.tab.cc" // lalr1.cc:859
    break;

  case 25:
#line 116 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("ORExpression", "");
                                                 yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ());
                                                 yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());
                                                 }
#line 908 "parser.tab.cc" // lalr1.cc:859
    break;

  case 26:
#line 121 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = yystack_[0].value.as< Node * > ();}
#line 914 "parser.tab.cc" // lalr1.cc:859
    break;

  case 27:
#line 122 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("ANDExpression", "");
                                                  yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ());
                                                  yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());
                                                  }
#line 923 "parser.tab.cc" // lalr1.cc:859
    break;

  case 28:
#line 128 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = yystack_[0].value.as< Node * > ();}
#line 929 "parser.tab.cc" // lalr1.cc:859
    break;

  case 29:
#line 129 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("CMPexpression", "");
                                                       yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ());
                                                       yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());
                                                       }
#line 938 "parser.tab.cc" // lalr1.cc:859
    break;

  case 30:
#line 134 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = yystack_[0].value.as< Node * > ();}
#line 944 "parser.tab.cc" // lalr1.cc:859
    break;

  case 31:
#line 135 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("RelExpression", "");
                                                  yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ());
                                                  yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());
                                                  }
#line 953 "parser.tab.cc" // lalr1.cc:859
    break;

  case 32:
#line 139 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("RelExpression", "");
                                                  yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ());
                                                  yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());
                                                  }
#line 962 "parser.tab.cc" // lalr1.cc:859
    break;

  case 33:
#line 144 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = yystack_[0].value.as< Node * > ();}
#line 968 "parser.tab.cc" // lalr1.cc:859
    break;

  case 34:
#line 145 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("AddExpression", "");
                                                 yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ());
                                                 yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());
                                                 }
#line 977 "parser.tab.cc" // lalr1.cc:859
    break;

  case 35:
#line 150 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("SubExpression", "");
                                                 yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ());
                                                 yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());
                                                 }
#line 986 "parser.tab.cc" // lalr1.cc:859
    break;

  case 36:
#line 155 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = yystack_[0].value.as< Node * > ();}
#line 992 "parser.tab.cc" // lalr1.cc:859
    break;

  case 37:
#line 156 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = yystack_[0].value.as< Node * > ();}
#line 998 "parser.tab.cc" // lalr1.cc:859
    break;

  case 38:
#line 157 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = yystack_[0].value.as< Node * > ();}
#line 1004 "parser.tab.cc" // lalr1.cc:859
    break;

  case 39:
#line 158 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("MultExpression", "");
                                          yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ());
                                          yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());
                                          }
#line 1013 "parser.tab.cc" // lalr1.cc:859
    break;

  case 40:
#line 163 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("DivExpression", "");
                                          yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ());
                                          yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());
                                          }
#line 1022 "parser.tab.cc" // lalr1.cc:859
    break;

  case 41:
#line 167 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("MultExpression", "");
                                          yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ());
                                          yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());
                                          }
#line 1031 "parser.tab.cc" // lalr1.cc:859
    break;

  case 42:
#line 172 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("DivExpression", "");
                                          yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ());
                                          yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());
                                          }
#line 1040 "parser.tab.cc" // lalr1.cc:859
    break;

  case 43:
#line 177 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = yystack_[0].value.as< Node * > ();}
#line 1046 "parser.tab.cc" // lalr1.cc:859
    break;

  case 44:
#line 178 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("NegationExpression", "");
                                               yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());
                                               }
#line 1054 "parser.tab.cc" // lalr1.cc:859
    break;

  case 45:
#line 182 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("ParExpression", "");
                            yylhs.value.as< Node * > ()->children.push_back(yystack_[1].value.as< Node * > ());
                            }
#line 1062 "parser.tab.cc" // lalr1.cc:859
    break;

  case 46:
#line 185 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("ParExpression", "");
                                          yylhs.value.as< Node * > ()->children.push_back(yystack_[5].value.as< Node * > ());
                                          yylhs.value.as< Node * > ()->children.push_back(yystack_[3].value.as< Node * > ());
                                          yylhs.value.as< Node * > ()->children.push_back(yystack_[3].value.as< Node * > ());
                                          }
#line 1072 "parser.tab.cc" // lalr1.cc:859
    break;

  case 47:
#line 190 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("ParExpression", "");
                                          yylhs.value.as< Node * > ()->children.push_back(yystack_[4].value.as< Node * > ());
                                          yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ());
                                          }
#line 1081 "parser.tab.cc" // lalr1.cc:859
    break;

  case 48:
#line 194 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("ParExpression", "");
                                          yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ());
                                          }
#line 1089 "parser.tab.cc" // lalr1.cc:859
    break;

  case 49:
#line 197 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("ParExpression", "");
                                          yylhs.value.as< Node * > ()->children.push_back(yystack_[1].value.as< Node * > ());
                                          }
#line 1097 "parser.tab.cc" // lalr1.cc:859
    break;

  case 50:
#line 200 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("ParExpression", "");
                                          yylhs.value.as< Node * > ()->children.push_back(yystack_[3].value.as< Node * > ());
                                          yylhs.value.as< Node * > ()->children.push_back(yystack_[1].value.as< Node * > ());
                                          }
#line 1106 "parser.tab.cc" // lalr1.cc:859
    break;

  case 51:
#line 205 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("classdeclaration", "");}
#line 1112 "parser.tab.cc" // lalr1.cc:859
    break;

  case 52:
#line 206 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("vardeclaration", "");
                                              yylhs.value.as< Node * > ()->children.push_back(yystack_[1].value.as< Node * > ());
                                              yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());
                                              }
#line 1121 "parser.tab.cc" // lalr1.cc:859
    break;

  case 53:
#line 211 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("classdeclaration", "");}
#line 1127 "parser.tab.cc" // lalr1.cc:859
    break;

  case 54:
#line 212 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("classdeclaration", "");
                                                yylhs.value.as< Node * > ()->children.push_back(yystack_[1].value.as< Node * > ());
                                                yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());
                                                }
#line 1136 "parser.tab.cc" // lalr1.cc:859
    break;

  case 55:
#line 217 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("statement_rep_none", "");}
#line 1142 "parser.tab.cc" // lalr1.cc:859
    break;

  case 56:
#line 218 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("statement_rep", "");
                                         yylhs.value.as< Node * > ()->children.push_back(yystack_[1].value.as< Node * > ());
                                         yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());
                                         }
#line 1151 "parser.tab.cc" // lalr1.cc:859
    break;

  case 57:
#line 223 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("classdeclaration", "");}
#line 1157 "parser.tab.cc" // lalr1.cc:859
    break;

  case 58:
#line 224 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("methoddeclaration", "");
                                             yylhs.value.as< Node * > ()->children.push_back(yystack_[1].value.as< Node * > ());
                                             yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());
                                             }
#line 1166 "parser.tab.cc" // lalr1.cc:859
    break;

  case 59:
#line 229 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("classdeclaration", "");}
#line 1172 "parser.tab.cc" // lalr1.cc:859
    break;

  case 60:
#line 230 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("parameterdeclaration", "");
                            yylhs.value.as< Node * > ()->children.push_back(yystack_[1].value.as< Node * > ());
                            yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());
                            }
#line 1181 "parser.tab.cc" // lalr1.cc:859
    break;

  case 61:
#line 234 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("parameterdeclaration", "");
                                                    yylhs.value.as< Node * > ()->children.push_back(yystack_[3].value.as< Node * > ());
                                                    yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ());
                                                    yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());
                                                    }
#line 1191 "parser.tab.cc" // lalr1.cc:859
    break;

  case 62:
#line 240 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("classdeclaration", "");}
#line 1197 "parser.tab.cc" // lalr1.cc:859
    break;

  case 63:
#line 241 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("argdeclaration", "");
                            yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());
                            }
#line 1205 "parser.tab.cc" // lalr1.cc:859
    break;

  case 64:
#line 244 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("argdeclaration", "");
                                             yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ());
                                             yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());
                                             }
#line 1214 "parser.tab.cc" // lalr1.cc:859
    break;

  case 65:
#line 250 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("identifier", yystack_[0].value.as< std::string > ());}
#line 1220 "parser.tab.cc" // lalr1.cc:859
    break;

  case 66:
#line 252 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("NUM", yystack_[0].value.as< std::string > ());}
#line 1226 "parser.tab.cc" // lalr1.cc:859
    break;

  case 67:
#line 253 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = yystack_[1].value.as< Node * > ();}
#line 1232 "parser.tab.cc" // lalr1.cc:859
    break;


#line 1236 "parser.tab.cc" // lalr1.cc:859
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
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

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
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
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
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
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

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
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what());
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
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
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (!yyla.empty ())
      {
        int yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
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
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
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
        YYCASE_(0, YY_("syntax error"));
        YYCASE_(1, YY_("syntax error, unexpected %s"));
        YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    size_t yyi = 0;
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


  const signed char parser::yypact_ninf_ = -56;

  const signed char parser::yytable_ninf_ = -36;

  const short int
  parser::yypact_[] =
  {
     -34,   -32,    24,   -56,   -56,    -4,   -56,    20,     2,   -56,
     -32,   -56,    35,   -26,    32,   -56,   -32,    41,    44,    43,
      95,   104,   -56,   -56,   -32,   -15,   -56,   -56,    86,   121,
      90,   -56,    44,   -56,    44,   129,   -56,   -56,   -32,   -14,
     125,   135,   -56,   -32,    23,   140,   119,   -32,   147,   122,
     -56,   141,   123,    61,    31,    44,   -56,   152,   154,   159,
      61,   132,    -6,    61,   127,    -6,   -56,    31,   103,   103,
     103,   139,   144,   103,   103,   -56,   103,   133,   103,   103,
       6,   -56,   -56,   -56,   -56,   208,   -56,   -56,   -56,   -56,
      50,    76,   -56,   -56,   -56,   -56,   217,   231,   -56,   -56,
      78,   149,   157,   103,   240,   303,   170,   175,    61,   103,
      10,   103,   103,   103,   103,   103,   103,   103,    27,    27,
     142,    61,   165,   -56,   155,   177,   -56,   103,   183,   162,
     262,   -56,   190,   303,   303,   303,   303,   303,   303,   124,
     126,   103,   -56,   -56,   -56,   -56,   -56,   -56,   103,   -56,
     163,   281,   -56,    61,   -56,   116,   254,   185,   -56,   -56,
     -56,   -56,   289,   184,   -56,   -56,   103,   -56,   -56
  };

  const unsigned char
  parser::yydefact_[] =
  {
       0,     0,     0,    53,    65,     0,     1,     0,     0,     2,
       0,    54,     0,     0,     0,    51,     0,     0,    57,     0,
       0,    11,    10,    52,     0,     0,    12,    51,     0,     0,
       0,     4,     0,    58,    57,     0,     9,     6,     0,     0,
       0,     0,     5,     0,     0,     0,     0,     0,     0,     0,
      51,    60,     0,     0,    55,    59,    51,     0,     0,     0,
      55,     0,     0,    55,     0,    12,    61,    55,     0,     0,
       0,     0,     0,     0,     0,    56,     0,     0,     0,     0,
       0,    22,    21,    20,    66,     0,    19,    24,    26,    28,
      30,    33,    36,    43,    38,    37,     0,     0,    13,     3,
       0,     0,     0,     0,     0,    44,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    17,     0,     0,    45,     0,     0,     0,
       0,    48,     0,    29,    31,    32,    25,    27,     0,    33,
      33,     0,    41,    39,    42,    40,    16,    15,     0,     7,
       0,     0,    23,     0,    50,     0,     0,     0,     8,    49,
      14,    47,    63,     0,    67,    18,    62,    46,    64
  };

  const short int
  parser::yypgoto_[] =
  {
     -56,   -56,   -56,   -56,   -56,   -56,   -30,   -52,   -29,   -56,
     -56,   -56,   -56,   -56,    33,   -56,   -56,   -20,   -56,   -55,
     171,   153,    47,    -1,   -22
  };

  const short int
  parser::yydefgoto_[] =
  {
      -1,     2,     3,    11,    23,    33,    24,    63,   138,    86,
      87,    88,    89,    90,    91,    92,    93,    18,     7,    64,
      25,    48,   163,    94,    95
  };

  const short int
  parser::yytable_[] =
  {
       5,    61,    38,    73,     1,    71,    15,    34,    75,    13,
     106,    16,    77,     4,    47,    19,    74,    26,    31,    42,
       9,    32,    32,    30,     6,    47,   131,    21,     8,    46,
      54,    26,   141,    26,    57,    21,    67,    41,    12,    85,
      96,    97,    45,    26,   100,   101,    51,   102,    21,   104,
     105,     4,    62,    65,    26,     4,   129,    22,    10,    62,
      58,    59,    62,    60,    57,    22,    65,   116,     4,   147,
     117,    84,     4,    17,   125,    27,     4,    14,    22,   107,
     130,    20,   133,   134,   135,   136,   137,   109,   122,     4,
      58,    59,   110,    60,   118,   119,   143,   145,   151,   111,
      28,   160,   112,   113,   114,   115,     4,    62,    78,   132,
      79,    80,   156,    29,    81,    82,    83,   142,   144,   157,
      62,    78,   161,    79,    80,    35,   162,    81,    82,    83,
     -35,    36,   -34,    37,   -35,    43,   -34,   162,    40,   -35,
      44,   -34,   118,   119,   118,   119,    49,    84,     4,   139,
     140,    50,    62,    52,    53,    56,    55,    68,   109,    69,
      84,     4,    76,   110,    70,    72,   109,   -35,   103,   -34,
     111,   110,    98,   112,   113,   114,   115,    99,   111,   127,
     128,   112,   113,   114,   115,   146,   109,   148,   149,   152,
     167,   110,   123,   153,   109,   155,   158,     0,   111,   110,
     124,   112,   113,   114,   115,    39,   111,     0,    66,   112,
     113,   114,   115,   168,   108,     0,     0,   109,     0,     0,
     150,     0,   110,   120,     0,     0,   109,     0,   165,   111,
       0,   110,   112,   113,   114,   115,     0,   121,   111,     0,
     109,   112,   113,   114,   115,   110,   126,     0,     0,   109,
       0,     0,   111,     0,   110,   112,   113,   114,   115,     0,
     164,   111,     0,   109,   112,   113,   114,   115,   110,     0,
       0,   109,   154,     0,     0,   111,   110,     0,   112,   113,
     114,   115,     0,   111,     0,     0,   112,   113,   114,   115,
     109,   159,     0,     0,     0,   110,     0,     0,   109,     0,
       0,     0,   111,   110,   166,   112,   113,   114,   115,     0,
     111,     0,   109,   112,   113,   114,   115,   110,     0,     0,
       0,     0,     0,     0,   111,     0,     0,   112,   113,   114,
     115
  };

  const short int
  parser::yycheck_[] =
  {
       1,    53,    32,     9,    38,    60,    32,    27,    63,    10,
       4,    37,    67,    45,    44,    16,    22,    18,    33,    33,
       0,    36,    36,    24,     0,    55,    16,     4,    32,     6,
      50,    32,     5,    34,     3,     4,    56,    38,    36,    68,
      69,    70,    43,    44,    73,    74,    47,    76,     4,    78,
      79,    45,    53,    54,    55,    45,   108,    34,    38,    60,
      29,    30,    63,    32,     3,    34,    67,    17,    45,   121,
      20,    44,    45,    41,   103,    32,    45,    42,    34,    80,
     109,    40,   111,   112,   113,   114,   115,     9,    10,    45,
      29,    30,    14,    32,    18,    19,   118,   119,   127,    21,
       5,   153,    24,    25,    26,    27,    45,   108,     5,   110,
       7,     8,   141,     9,    11,    12,    13,   118,   119,   148,
     121,     5,     6,     7,     8,    39,   155,    11,    12,    13,
       6,    10,     6,    43,    10,    10,    10,   166,     9,    15,
       5,    15,    18,    19,    18,    19,     6,    44,    45,   116,
     117,    32,   153,     6,    32,    32,    15,     5,     9,     5,
      44,    45,    35,    14,     5,    33,     9,    43,    35,    43,
      21,    14,    33,    24,    25,    26,    27,    33,    21,     9,
       5,    24,    25,    26,    27,    43,     9,    22,    33,     6,
       6,    14,    43,    31,     9,     5,    33,    -1,    21,    14,
      43,    24,    25,    26,    27,    34,    21,    -1,    55,    24,
      25,    26,    27,   166,     6,    -1,    -1,     9,    -1,    -1,
      43,    -1,    14,     6,    -1,    -1,     9,    -1,    43,    21,
      -1,    14,    24,    25,    26,    27,    -1,     6,    21,    -1,
       9,    24,    25,    26,    27,    14,     6,    -1,    -1,     9,
      -1,    -1,    21,    -1,    14,    24,    25,    26,    27,    -1,
       6,    21,    -1,     9,    24,    25,    26,    27,    14,    -1,
      -1,     9,    10,    -1,    -1,    21,    14,    -1,    24,    25,
      26,    27,    -1,    21,    -1,    -1,    24,    25,    26,    27,
       9,    10,    -1,    -1,    -1,    14,    -1,    -1,     9,    -1,
      -1,    -1,    21,    14,    15,    24,    25,    26,    27,    -1,
      21,    -1,     9,    24,    25,    26,    27,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    21,    -1,    -1,    24,    25,    26,
      27
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,    38,    47,    48,    45,    69,     0,    64,    32,     0,
      38,    49,    36,    69,    42,    32,    37,    41,    63,    69,
      40,     4,    34,    50,    52,    66,    69,    32,     5,     9,
      69,    33,    36,    51,    63,    39,    10,    43,    52,    66,
       9,    69,    33,    10,     5,    69,     6,    52,    67,     6,
      32,    69,     6,    32,    63,    15,    32,     3,    29,    30,
      32,    53,    69,    53,    65,    69,    67,    63,     5,     5,
       5,    65,    33,     9,    22,    65,    35,    65,     5,     7,
       8,    11,    12,    13,    44,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    69,    70,    54,    54,    33,    33,
      54,    54,    54,    35,    54,    54,     4,    69,     6,     9,
      14,    21,    24,    25,    26,    27,    17,    20,    18,    19,
       6,     6,    10,    43,    43,    54,     6,     9,     5,    53,
      54,    16,    69,    54,    54,    54,    54,    54,    54,    60,
      60,     5,    69,    70,    69,    70,    43,    53,    22,    33,
      43,    54,     6,    31,    10,     5,    54,    54,    33,    10,
      53,     6,    54,    68,     6,    43,    15,     6,    68
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    46,    47,    48,    49,    49,    50,    51,    51,    52,
      52,    52,    52,    53,    53,    53,    53,    53,    53,    54,
      54,    54,    54,    54,    55,    55,    56,    56,    57,    57,
      58,    58,    58,    59,    59,    59,    60,    60,    60,    60,
      60,    60,    60,    61,    61,    62,    62,    62,    62,    62,
      62,    63,    63,    64,    64,    65,    65,    66,    66,    67,
      67,    67,    68,    68,    68,    69,    70,    70
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     3,    17,     6,     8,     3,    12,    13,     3,
       1,     1,     1,     3,     7,     5,     5,     4,     7,     1,
       1,     1,     1,     4,     1,     3,     1,     3,     1,     3,
       1,     3,     3,     1,     3,     3,     1,     1,     1,     3,
       3,     3,     3,     1,     2,     3,     6,     5,     3,     5,
       4,     0,     2,     0,     2,     0,     2,     0,     2,     0,
       2,     4,     0,     1,     3,     1,     1,     3
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "IF", "INT", "LP", "RP",
  "ESX", "NEW", "LB", "RB", "THIS", "FALSE", "TRUE", "DOT", "COMMA",
  "LENGTH", "SUB", "MUL", "DIV", "PLUS", "CMP", "EQUAL", "GT", "LT", "MT",
  "OR", "AND", "COMMENT", "SYSTEMOUTPRINT", "WHILE", "ELSE", "LCB", "RCB",
  "BOOLEAN", "RETURN", "PUBLIC", "EXTENDS", "CLASS", "STRING", "MAIN",
  "VOID", "STATIC", "SEMICOLON", "NUM", "WORD", "$accept", "goal",
  "mainclass", "classdeclaration", "vardeclaration", "methoddeclaration",
  "type", "statement", "expression", "OR_expression", "AND_expression",
  "EQUALITY_expression", "REL_expression", "addExpression",
  "multExpression", "negation_expression", "par_expression",
  "vardeclaration_rep", "classdeclaration_rep", "statement_rep",
  "methoddeclaration_rep", "parameterdeclaration_rep",
  "argdeclaration_rep", "identifier", "number", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned char
  parser::yyrline_[] =
  {
       0,    28,    28,    34,    40,    45,    52,    57,    64,    73,
      75,    77,    79,    83,    87,    92,    96,    99,   103,   109,
     110,   111,   112,   113,   115,   116,   121,   122,   128,   129,
     134,   135,   139,   144,   145,   150,   155,   156,   157,   158,
     163,   167,   172,   177,   178,   182,   185,   190,   194,   197,
     200,   205,   206,   211,   212,   217,   218,   223,   224,   229,
     230,   234,   240,   241,   244,   250,   252,   253
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
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG



} // yy
#line 1741 "parser.tab.cc" // lalr1.cc:1167
