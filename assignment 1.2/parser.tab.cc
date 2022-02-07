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
      case 45: // goal
      case 46: // mainclass
      case 47: // classdeclaration
      case 48: // vardeclaration
      case 49: // methoddeclaration
      case 50: // type
      case 51: // statement
      case 52: // expression
      case 53: // otherExpression
      case 54: // boolExpression
      case 55: // funccallExpression
      case 56: // lengthExpression
      case 57: // indexExpression
      case 58: // logExpression
      case 59: // addExpression
      case 60: // multExpression
      case 61: // vardeclaration_rep
      case 62: // classdeclaration_rep
      case 63: // statement_rep
      case 64: // methoddeclaration_rep
      case 65: // parameterdeclaration_rep
      case 66: // argdeclaration_rep
      case 67: // identifier
      case 68: // number
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
      case 23: // LT
      case 24: // MT
      case 25: // OR
      case 26: // AND
      case 27: // SYSTEMOUTPRINT
      case 28: // WHILE
      case 29: // ELSE
      case 30: // LCB
      case 31: // RCB
      case 32: // BOOLEAN
      case 33: // RETURN
      case 34: // PUBLIC
      case 35: // EXTENDS
      case 36: // CLASS
      case 37: // STRING
      case 38: // MAIN
      case 39: // VOID
      case 40: // STATIC
      case 41: // SEMICOLON
      case 42: // NUM
      case 43: // WORD
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
      case 45: // goal
      case 46: // mainclass
      case 47: // classdeclaration
      case 48: // vardeclaration
      case 49: // methoddeclaration
      case 50: // type
      case 51: // statement
      case 52: // expression
      case 53: // otherExpression
      case 54: // boolExpression
      case 55: // funccallExpression
      case 56: // lengthExpression
      case 57: // indexExpression
      case 58: // logExpression
      case 59: // addExpression
      case 60: // multExpression
      case 61: // vardeclaration_rep
      case 62: // classdeclaration_rep
      case 63: // statement_rep
      case 64: // methoddeclaration_rep
      case 65: // parameterdeclaration_rep
      case 66: // argdeclaration_rep
      case 67: // identifier
      case 68: // number
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
      case 23: // LT
      case 24: // MT
      case 25: // OR
      case 26: // AND
      case 27: // SYSTEMOUTPRINT
      case 28: // WHILE
      case 29: // ELSE
      case 30: // LCB
      case 31: // RCB
      case 32: // BOOLEAN
      case 33: // RETURN
      case 34: // PUBLIC
      case 35: // EXTENDS
      case 36: // CLASS
      case 37: // STRING
      case 38: // MAIN
      case 39: // VOID
      case 40: // STATIC
      case 41: // SEMICOLON
      case 42: // NUM
      case 43: // WORD
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
      case 45: // goal
      case 46: // mainclass
      case 47: // classdeclaration
      case 48: // vardeclaration
      case 49: // methoddeclaration
      case 50: // type
      case 51: // statement
      case 52: // expression
      case 53: // otherExpression
      case 54: // boolExpression
      case 55: // funccallExpression
      case 56: // lengthExpression
      case 57: // indexExpression
      case 58: // logExpression
      case 59: // addExpression
      case 60: // multExpression
      case 61: // vardeclaration_rep
      case 62: // classdeclaration_rep
      case 63: // statement_rep
      case 64: // methoddeclaration_rep
      case 65: // parameterdeclaration_rep
      case 66: // argdeclaration_rep
      case 67: // identifier
      case 68: // number
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
      case 23: // LT
      case 24: // MT
      case 25: // OR
      case 26: // AND
      case 27: // SYSTEMOUTPRINT
      case 28: // WHILE
      case 29: // ELSE
      case 30: // LCB
      case 31: // RCB
      case 32: // BOOLEAN
      case 33: // RETURN
      case 34: // PUBLIC
      case 35: // EXTENDS
      case 36: // CLASS
      case 37: // STRING
      case 38: // MAIN
      case 39: // VOID
      case 40: // STATIC
      case 41: // SEMICOLON
      case 42: // NUM
      case 43: // WORD
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
#line 709 "parser.tab.cc" // lalr1.cc:859
    break;

  case 3:
#line 34 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("MainClass", "");
                          yylhs.value.as< Node * > ()->children.push_back(yystack_[15].value.as< Node * > ());
                          yylhs.value.as< Node * > ()->children.push_back(yystack_[5].value.as< Node * > ());
                          yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ());
                          }
#line 719 "parser.tab.cc" // lalr1.cc:859
    break;

  case 4:
#line 40 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("ClassDeclaration","" );
                          yylhs.value.as< Node * > ()->children.push_back(yystack_[4].value.as< Node * > ());
                          yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ());
                          yylhs.value.as< Node * > ()->children.push_back(yystack_[1].value.as< Node * > ());
                          }
#line 729 "parser.tab.cc" // lalr1.cc:859
    break;

  case 5:
#line 45 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("ClassDeclaration", "");
                                          yylhs.value.as< Node * > ()->children.push_back(yystack_[6].value.as< Node * > ());
                                          yylhs.value.as< Node * > ()->children.push_back(yystack_[4].value.as< Node * > ());
                                          yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ());
                                          yylhs.value.as< Node * > ()->children.push_back(yystack_[1].value.as< Node * > ());
                                          }
#line 740 "parser.tab.cc" // lalr1.cc:859
    break;

  case 6:
#line 52 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("VarDeclaration", "");
                          yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ());
                          yylhs.value.as< Node * > ()->children.push_back(yystack_[1].value.as< Node * > ());
                          }
#line 749 "parser.tab.cc" // lalr1.cc:859
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
#line 761 "parser.tab.cc" // lalr1.cc:859
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
#line 774 "parser.tab.cc" // lalr1.cc:859
    break;

  case 9:
#line 73 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("Type", "");
                          }
#line 781 "parser.tab.cc" // lalr1.cc:859
    break;

  case 10:
#line 75 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("Type", "");
                          }
#line 788 "parser.tab.cc" // lalr1.cc:859
    break;

  case 11:
#line 77 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("Type", "");
                          }
#line 795 "parser.tab.cc" // lalr1.cc:859
    break;

  case 12:
#line 79 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("Type", "");
                          yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());
                          }
#line 803 "parser.tab.cc" // lalr1.cc:859
    break;

  case 13:
#line 83 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("Statement", "");
                          yylhs.value.as< Node * > ()->children.push_back(yystack_[1].value.as< Node * > ());
                          }
#line 811 "parser.tab.cc" // lalr1.cc:859
    break;

  case 14:
#line 86 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("Statement", yystack_[6].value.as< std::string > ());
                          yylhs.value.as< Node * > ()->children.push_back(yystack_[4].value.as< Node * > ());
                          yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ());
                          yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());
                          }
#line 821 "parser.tab.cc" // lalr1.cc:859
    break;

  case 15:
#line 91 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("Statement", yystack_[4].value.as< std::string > ());
                          yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ());
                          yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());
                          }
#line 830 "parser.tab.cc" // lalr1.cc:859
    break;

  case 16:
#line 95 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("Statement", "");
                          yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ());
                          }
#line 838 "parser.tab.cc" // lalr1.cc:859
    break;

  case 17:
#line 98 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("Statement", "");
                          yylhs.value.as< Node * > ()->children.push_back(yystack_[3].value.as< Node * > ());
                          yylhs.value.as< Node * > ()->children.push_back(yystack_[1].value.as< Node * > ());
                          }
#line 847 "parser.tab.cc" // lalr1.cc:859
    break;

  case 18:
#line 102 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("Statement", "");
                          yylhs.value.as< Node * > ()->children.push_back(yystack_[6].value.as< Node * > ());
                          yylhs.value.as< Node * > ()->children.push_back(yystack_[4].value.as< Node * > ());
                          yylhs.value.as< Node * > ()->children.push_back(yystack_[1].value.as< Node * > ());
                          }
#line 857 "parser.tab.cc" // lalr1.cc:859
    break;

  case 19:
#line 108 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("Expression", "");
                          yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());
                          }
#line 865 "parser.tab.cc" // lalr1.cc:859
    break;

  case 20:
#line 111 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("Expression", "");
                          yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());
                          }
#line 873 "parser.tab.cc" // lalr1.cc:859
    break;

  case 21:
#line 114 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("Expression", "");
                          yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());
                          }
#line 881 "parser.tab.cc" // lalr1.cc:859
    break;

  case 22:
#line 117 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("Expression", "");
                          yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());
                          }
#line 889 "parser.tab.cc" // lalr1.cc:859
    break;

  case 23:
#line 120 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("Expression", "");
                          yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());
                          }
#line 897 "parser.tab.cc" // lalr1.cc:859
    break;

  case 24:
#line 123 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("Expression", "");
                          yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());
                          }
#line 905 "parser.tab.cc" // lalr1.cc:859
    break;

  case 25:
#line 126 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("Expression", "");
                          yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());
                          }
#line 913 "parser.tab.cc" // lalr1.cc:859
    break;

  case 26:
#line 129 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("Expression", "");
                          yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());
                          }
#line 921 "parser.tab.cc" // lalr1.cc:859
    break;

  case 27:
#line 133 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("otherExpression", "");}
#line 927 "parser.tab.cc" // lalr1.cc:859
    break;

  case 28:
#line 134 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("otherExpression", "");
                                                 yylhs.value.as< Node * > ()->children.push_back(yystack_[1].value.as< Node * > ());
                                                 }
#line 935 "parser.tab.cc" // lalr1.cc:859
    break;

  case 29:
#line 137 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("otherExpression", "");
                                                 yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ());
                                                 }
#line 943 "parser.tab.cc" // lalr1.cc:859
    break;

  case 30:
#line 140 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("otherExpression", "");
                                                 yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());
                                                 }
#line 951 "parser.tab.cc" // lalr1.cc:859
    break;

  case 31:
#line 143 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("otherExpression", "");
                                                 yylhs.value.as< Node * > ()->children.push_back(yystack_[1].value.as< Node * > ());
                                                 }
#line 959 "parser.tab.cc" // lalr1.cc:859
    break;

  case 32:
#line 147 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("boolExpression", yystack_[0].value.as< std::string > ());}
#line 965 "parser.tab.cc" // lalr1.cc:859
    break;

  case 33:
#line 148 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("boolExpression", yystack_[0].value.as< std::string > ());}
#line 971 "parser.tab.cc" // lalr1.cc:859
    break;

  case 34:
#line 150 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("funccallExpression", "");
                                                 yylhs.value.as< Node * > ()->children.push_back(yystack_[5].value.as< Node * > ());
                                                 yylhs.value.as< Node * > ()->children.push_back(yystack_[3].value.as< Node * > ());
                                                 yylhs.value.as< Node * > ()->children.push_back(yystack_[1].value.as< Node * > ());
                                                 }
#line 981 "parser.tab.cc" // lalr1.cc:859
    break;

  case 35:
#line 155 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("funccallExpression", "");
                                                                   yylhs.value.as< Node * > ()->children.push_back(yystack_[4].value.as< Node * > ());
                                                                   yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ());
                                                                   }
#line 990 "parser.tab.cc" // lalr1.cc:859
    break;

  case 36:
#line 160 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("lengthExpression", "");
                                                 yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ());
                                                 }
#line 998 "parser.tab.cc" // lalr1.cc:859
    break;

  case 37:
#line 165 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("indexExpression", "");
                                                 yylhs.value.as< Node * > ()->children.push_back(yystack_[3].value.as< Node * > ());
                                                 yylhs.value.as< Node * > ()->children.push_back(yystack_[1].value.as< Node * > ());
                                                 }
#line 1007 "parser.tab.cc" // lalr1.cc:859
    break;

  case 38:
#line 170 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("logExpression", "");
                                                 yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ());
                                                 yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());
                                                 }
#line 1016 "parser.tab.cc" // lalr1.cc:859
    break;

  case 39:
#line 174 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("logExpression", "");
                                                 yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ());
                                                 yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());
                                                 }
#line 1025 "parser.tab.cc" // lalr1.cc:859
    break;

  case 40:
#line 178 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("logExpression", "");
                                                 yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ());
                                                 yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());
                                                 }
#line 1034 "parser.tab.cc" // lalr1.cc:859
    break;

  case 41:
#line 182 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("logExpression", "");
                                                 yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ());
                                                 yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());
                                                 }
#line 1043 "parser.tab.cc" // lalr1.cc:859
    break;

  case 42:
#line 186 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("logExpression", "");
                                                 yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ());
                                                 yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());
                                                 }
#line 1052 "parser.tab.cc" // lalr1.cc:859
    break;

  case 43:
#line 191 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = yystack_[0].value.as< Node * > ();}
#line 1058 "parser.tab.cc" // lalr1.cc:859
    break;

  case 44:
#line 192 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("AddExpression", "");
                                                 yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ());
                                                 yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());
                                                 }
#line 1067 "parser.tab.cc" // lalr1.cc:859
    break;

  case 45:
#line 197 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("SubExpression", "");
                                                 yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ());
                                                 yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());
                                                 }
#line 1076 "parser.tab.cc" // lalr1.cc:859
    break;

  case 46:
#line 202 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = yystack_[0].value.as< Node * > ();}
#line 1082 "parser.tab.cc" // lalr1.cc:859
    break;

  case 47:
#line 203 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = yystack_[0].value.as< Node * > ();}
#line 1088 "parser.tab.cc" // lalr1.cc:859
    break;

  case 48:
#line 204 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("MultExpression", "");
                                          yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ());
                                          yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());
                                          }
#line 1097 "parser.tab.cc" // lalr1.cc:859
    break;

  case 49:
#line 209 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("DivExpression", "");
                                          yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ());
                                          yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());
                                          }
#line 1106 "parser.tab.cc" // lalr1.cc:859
    break;

  case 50:
#line 213 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("MultExpression", "");
                                          yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ());
                                          yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());
                                          }
#line 1115 "parser.tab.cc" // lalr1.cc:859
    break;

  case 51:
#line 218 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("DivExpression", "");
                                          yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ());
                                          yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());
                                          }
#line 1124 "parser.tab.cc" // lalr1.cc:859
    break;

  case 52:
#line 223 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("classdeclaration", "");}
#line 1130 "parser.tab.cc" // lalr1.cc:859
    break;

  case 53:
#line 224 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("vardeclaration", "");
                                              yylhs.value.as< Node * > ()->children.push_back(yystack_[1].value.as< Node * > ());
                                              yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());
                                              }
#line 1139 "parser.tab.cc" // lalr1.cc:859
    break;

  case 54:
#line 229 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("classdeclaration", "");}
#line 1145 "parser.tab.cc" // lalr1.cc:859
    break;

  case 55:
#line 230 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("classdeclaration", "");
                                                yylhs.value.as< Node * > ()->children.push_back(yystack_[1].value.as< Node * > ());
                                                yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());
                                                }
#line 1154 "parser.tab.cc" // lalr1.cc:859
    break;

  case 56:
#line 235 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("classdeclaration", "");}
#line 1160 "parser.tab.cc" // lalr1.cc:859
    break;

  case 57:
#line 236 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("statement", "");
                                         yylhs.value.as< Node * > ()->children.push_back(yystack_[1].value.as< Node * > ());
                                         yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());
                                         }
#line 1169 "parser.tab.cc" // lalr1.cc:859
    break;

  case 58:
#line 241 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("classdeclaration", "");}
#line 1175 "parser.tab.cc" // lalr1.cc:859
    break;

  case 59:
#line 242 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("methoddeclaration", "");
                                             yylhs.value.as< Node * > ()->children.push_back(yystack_[1].value.as< Node * > ());
                                             yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());
                                             }
#line 1184 "parser.tab.cc" // lalr1.cc:859
    break;

  case 60:
#line 247 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("classdeclaration", "");}
#line 1190 "parser.tab.cc" // lalr1.cc:859
    break;

  case 61:
#line 248 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("parameterdeclaration", "");
                            yylhs.value.as< Node * > ()->children.push_back(yystack_[1].value.as< Node * > ());
                            yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());
                            }
#line 1199 "parser.tab.cc" // lalr1.cc:859
    break;

  case 62:
#line 252 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("parameterdeclaration", "");
                                                    yylhs.value.as< Node * > ()->children.push_back(yystack_[3].value.as< Node * > ());
                                                    yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ());
                                                    yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());
                                                    }
#line 1209 "parser.tab.cc" // lalr1.cc:859
    break;

  case 63:
#line 258 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("classdeclaration", "");}
#line 1215 "parser.tab.cc" // lalr1.cc:859
    break;

  case 64:
#line 259 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("argdeclaration", "");
                            yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());
                            }
#line 1223 "parser.tab.cc" // lalr1.cc:859
    break;

  case 65:
#line 262 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("argdeclaration", "");
                                             yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ());
                                             yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());
                                             }
#line 1232 "parser.tab.cc" // lalr1.cc:859
    break;

  case 66:
#line 268 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("identifier", yystack_[0].value.as< std::string > ());}
#line 1238 "parser.tab.cc" // lalr1.cc:859
    break;

  case 67:
#line 270 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("NUM", yystack_[0].value.as< std::string > ());}
#line 1244 "parser.tab.cc" // lalr1.cc:859
    break;

  case 68:
#line 271 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = yystack_[1].value.as< Node * > ();}
#line 1250 "parser.tab.cc" // lalr1.cc:859
    break;


#line 1254 "parser.tab.cc" // lalr1.cc:859
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


  const signed char parser::yypact_ninf_ = -53;

  const signed char parser::yytable_ninf_ = -69;

  const short int
  parser::yypact_[] =
  {
     -28,   -33,    22,   -53,   -53,    -4,   -53,     3,    14,   -53,
     -33,   -53,    21,   -10,    24,   -53,   -33,    32,    15,    48,
      78,    91,   -53,   -53,   -33,   -27,   -53,   -53,    73,    96,
      67,   -53,    15,   -53,    15,   115,   -53,   -53,   -33,    26,
     122,   135,   -53,   -33,    12,   136,   111,   -33,   138,   117,
     -53,   130,   132,     8,     2,    15,   -53,   160,   169,   171,
       8,   150,     5,     8,   153,     5,   -53,     2,    60,    60,
      60,   152,   158,    60,    60,   -53,    60,   159,    60,    60,
      -2,   -53,   -53,   -53,   -53,   176,   -53,   -53,   -53,   -53,
     -53,   -53,    71,    86,    79,   -53,   182,   203,   -53,   -53,
     236,   112,   125,    60,   209,   281,   184,   189,     8,    60,
      -3,    60,    60,    60,    60,    60,     7,     7,     7,     7,
     157,     8,   188,   -53,   173,   146,   139,    60,   205,   185,
     254,   -53,   208,   281,   281,   281,   281,   281,    60,    86,
     -53,    86,   -53,   -53,   -53,   -53,   -53,   -53,    60,   -53,
     190,   260,   -53,     8,   -53,    69,   230,   154,   -53,   -53,
     -53,   -53,   273,   210,   -53,   -53,    60,   -53,   -53
  };

  const unsigned char
  parser::yydefact_[] =
  {
       0,     0,     0,    54,    66,     0,     1,     0,     0,     2,
       0,    55,     0,     0,     0,    52,     0,     0,    58,     0,
       0,    11,    10,    53,     0,     0,    12,    52,     0,     0,
       0,     4,     0,    59,    58,     0,     9,     6,     0,     0,
       0,     0,     5,     0,     0,     0,     0,     0,     0,     0,
      52,    61,     0,     0,    56,    60,    52,     0,     0,     0,
      56,     0,     0,    56,     0,    12,    62,    56,     0,     0,
       0,     0,     0,     0,     0,    57,     0,     0,     0,     0,
       0,    27,    33,    32,    67,     0,    26,    24,    23,    22,
      21,    20,    19,    43,    25,    46,     0,     0,    13,     3,
       0,     0,     0,     0,     0,    30,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    17,     0,     0,    31,     0,     0,     0,
       0,    36,     0,    40,    42,    41,    38,    39,     0,    45,
      47,    44,    50,    48,    51,    49,    16,    15,     0,     7,
       0,     0,    29,     0,    37,     0,     0,     0,     8,    28,
      14,    35,    64,     0,    68,    18,    63,    34,    65
  };

  const short int
  parser::yypgoto_[] =
  {
     -53,   -53,   -53,   -53,   -53,   -53,   129,   -52,    16,   -53,
     -53,   -53,   -53,   -53,   -53,   -53,     6,    37,   -53,   -39,
     186,   164,    56,    -1,    -5
  };

  const short int
  parser::yydefgoto_[] =
  {
      -1,     2,     3,    11,    23,    33,    24,    63,   162,    86,
      87,    88,    89,    90,    91,    92,    93,    18,     7,    64,
      25,    48,   163,    94,    95
  };

  const short int
  parser::yytable_[] =
  {
       5,    61,   106,     9,    31,    57,    21,    32,     1,    13,
       4,    57,   138,   131,    73,    19,    21,    26,    46,    21,
      15,    71,     6,    30,    75,    16,     8,    74,    77,    58,
      59,    26,    60,    26,    22,    58,    59,    41,    60,    10,
       4,     4,    45,    26,    22,     4,    51,    22,    12,    84,
       4,     4,    62,    65,    26,     4,   129,    42,     4,    62,
      32,    14,    62,    17,    34,    78,    65,    79,    80,   147,
      20,    81,    82,    83,    78,   161,    79,    80,    27,   107,
      81,    82,    83,    28,    85,    96,    97,    54,   116,   100,
     101,   117,   102,    67,   104,   105,   -47,   -47,   -47,   -47,
      29,   160,    84,     4,   118,   119,    36,    62,    37,   132,
      35,    84,     4,   143,   145,   140,   140,   142,   144,   125,
      62,   109,   139,   141,    40,   130,   110,   133,   134,   135,
     136,   137,    43,   111,   109,   112,   113,   114,   115,   110,
      44,    50,    49,   151,    52,    55,   111,    53,   112,   113,
     114,   115,    62,   123,   156,   109,   -68,   -68,   -68,   -68,
     110,    38,    56,   109,   157,    68,   124,   111,   110,   112,
     113,   114,   115,    47,    69,   111,    70,   112,   113,   114,
     115,    72,   108,    98,    47,   109,    76,   150,   120,    99,
     110,   109,   103,   127,   128,   165,   110,   111,   146,   112,
     113,   114,   115,   111,   149,   112,   113,   114,   115,   121,
     148,   152,   109,   155,   153,   126,   167,   110,   109,    66,
      39,   158,   168,   110,   111,     0,   112,   113,   114,   115,
     111,     0,   112,   113,   114,   115,   164,     0,     0,   109,
       0,     0,     0,     0,   110,   109,   122,     0,     0,     0,
     110,   111,     0,   112,   113,   114,   115,   111,     0,   112,
     113,   114,   115,   109,   154,     0,     0,     0,   110,   109,
     159,     0,     0,     0,   110,   111,     0,   112,   113,   114,
     115,   111,   109,   112,   113,   114,   115,   110,   166,     0,
     109,     0,     0,     0,   111,   110,   112,   113,   114,   115,
       0,     0,   111,     0,   112,   113,   114,   115
  };

  const short int
  parser::yycheck_[] =
  {
       1,    53,     4,     0,    31,     3,     4,    34,    36,    10,
      43,     3,     5,    16,     9,    16,     4,    18,     6,     4,
      30,    60,     0,    24,    63,    35,    30,    22,    67,    27,
      28,    32,    30,    34,    32,    27,    28,    38,    30,    36,
      43,    43,    43,    44,    32,    43,    47,    32,    34,    42,
      43,    43,    53,    54,    55,    43,   108,    31,    43,    60,
      34,    40,    63,    39,    27,     5,    67,     7,     8,   121,
      38,    11,    12,    13,     5,     6,     7,     8,    30,    80,
      11,    12,    13,     5,    68,    69,    70,    50,    17,    73,
      74,    20,    76,    56,    78,    79,    17,    18,    19,    20,
       9,   153,    42,    43,    18,    19,    10,   108,    41,   110,
      37,    42,    43,   118,   119,   116,   117,   118,   119,   103,
     121,     9,   116,   117,     9,   109,    14,   111,   112,   113,
     114,   115,    10,    21,     9,    23,    24,    25,    26,    14,
       5,    30,     6,   127,     6,    15,    21,    30,    23,    24,
      25,    26,   153,    41,   138,     9,    17,    18,    19,    20,
      14,    32,    30,     9,   148,     5,    41,    21,    14,    23,
      24,    25,    26,    44,     5,    21,     5,    23,    24,    25,
      26,    31,     6,    31,    55,     9,    33,    41,     6,    31,
      14,     9,    33,     9,     5,    41,    14,    21,    41,    23,
      24,    25,    26,    21,    31,    23,    24,    25,    26,     6,
      22,     6,     9,     5,    29,     6,     6,    14,     9,    55,
      34,    31,   166,    14,    21,    -1,    23,    24,    25,    26,
      21,    -1,    23,    24,    25,    26,     6,    -1,    -1,     9,
      -1,    -1,    -1,    -1,    14,     9,    10,    -1,    -1,    -1,
      14,    21,    -1,    23,    24,    25,    26,    21,    -1,    23,
      24,    25,    26,     9,    10,    -1,    -1,    -1,    14,     9,
      10,    -1,    -1,    -1,    14,    21,    -1,    23,    24,    25,
      26,    21,     9,    23,    24,    25,    26,    14,    15,    -1,
       9,    -1,    -1,    -1,    21,    14,    23,    24,    25,    26,
      -1,    -1,    21,    -1,    23,    24,    25,    26
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,    36,    45,    46,    43,    67,     0,    62,    30,     0,
      36,    47,    34,    67,    40,    30,    35,    39,    61,    67,
      38,     4,    32,    48,    50,    64,    67,    30,     5,     9,
      67,    31,    34,    49,    61,    37,    10,    41,    50,    64,
       9,    67,    31,    10,     5,    67,     6,    50,    65,     6,
      30,    67,     6,    30,    61,    15,    30,     3,    27,    28,
      30,    51,    67,    51,    63,    67,    65,    61,     5,     5,
       5,    63,    31,     9,    22,    63,    33,    63,     5,     7,
       8,    11,    12,    13,    42,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    67,    68,    52,    52,    31,    31,
      52,    52,    52,    33,    52,    52,     4,    67,     6,     9,
      14,    21,    23,    24,    25,    26,    17,    20,    18,    19,
       6,     6,    10,    41,    41,    52,     6,     9,     5,    51,
      52,    16,    67,    52,    52,    52,    52,    52,     5,    60,
      67,    60,    67,    68,    67,    68,    41,    51,    22,    31,
      41,    52,     6,    29,    10,     5,    52,    52,    31,    10,
      51,     6,    52,    66,     6,    41,    15,     6,    66
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    44,    45,    46,    47,    47,    48,    49,    49,    50,
      50,    50,    50,    51,    51,    51,    51,    51,    51,    52,
      52,    52,    52,    52,    52,    52,    52,    53,    53,    53,
      53,    53,    54,    54,    55,    55,    56,    57,    58,    58,
      58,    58,    58,    59,    59,    59,    60,    60,    60,    60,
      60,    60,    61,    61,    62,    62,    63,    63,    64,    64,
      65,    65,    65,    66,    66,    66,    67,    68,    68
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     3,    17,     6,     8,     3,    12,    13,     3,
       1,     1,     1,     3,     7,     5,     5,     4,     7,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     5,     4,
       2,     3,     1,     1,     6,     5,     3,     4,     3,     3,
       3,     3,     3,     1,     3,     3,     1,     1,     3,     3,
       3,     3,     0,     2,     0,     2,     0,     2,     0,     2,
       0,     2,     4,     0,     1,     3,     1,     1,     3
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "IF", "INT", "LP", "RP",
  "ESX", "NEW", "LB", "RB", "THIS", "FALSE", "TRUE", "DOT", "COMMA",
  "LENGTH", "SUB", "MUL", "DIV", "PLUS", "CMP", "EQUAL", "LT", "MT", "OR",
  "AND", "SYSTEMOUTPRINT", "WHILE", "ELSE", "LCB", "RCB", "BOOLEAN",
  "RETURN", "PUBLIC", "EXTENDS", "CLASS", "STRING", "MAIN", "VOID",
  "STATIC", "SEMICOLON", "NUM", "WORD", "$accept", "goal", "mainclass",
  "classdeclaration", "vardeclaration", "methoddeclaration", "type",
  "statement", "expression", "otherExpression", "boolExpression",
  "funccallExpression", "lengthExpression", "indexExpression",
  "logExpression", "addExpression", "multExpression", "vardeclaration_rep",
  "classdeclaration_rep", "statement_rep", "methoddeclaration_rep",
  "parameterdeclaration_rep", "argdeclaration_rep", "identifier", "number", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
  parser::yyrline_[] =
  {
       0,    28,    28,    34,    40,    45,    52,    57,    64,    73,
      75,    77,    79,    83,    86,    91,    95,    98,   102,   108,
     111,   114,   117,   120,   123,   126,   129,   133,   134,   137,
     140,   143,   147,   148,   150,   155,   160,   165,   170,   174,
     178,   182,   186,   191,   192,   197,   202,   203,   204,   209,
     213,   218,   223,   224,   229,   230,   235,   236,   241,   242,
     247,   248,   252,   258,   259,   262,   268,   270,   271
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
#line 1752 "parser.tab.cc" // lalr1.cc:1167
