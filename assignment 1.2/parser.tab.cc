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
#line 12 "parser.yy" // lalr1.cc:413

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
      case 45: // expression
      case 46: // addExpression
      case 47: // multExpression
      case 48: // factor
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
      case 22: // LT
      case 23: // MT
      case 24: // OR
      case 25: // AND
      case 26: // COMMENT
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
      case 47: // goal
      case 48: // mainclass
      case 49: // classdeclaration
      case 50: // vardeclaration
      case 51: // methoddeclaration
      case 52: // type
      case 53: // statement
      case 54: // expression
      case 55: // otherExpression
      case 56: // boolExpression
      case 57: // funccallExpression
      case 58: // lengthExpression
      case 59: // indexExpression
      case 60: // logExpression
      case 61: // addExpression
      case 62: // multExpression
      case 63: // number
      case 64: // identifier
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
      case 45: // expression
      case 46: // addExpression
      case 47: // multExpression
      case 48: // factor
        yylhs.value.build< Node * > ();
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
      case 22: // LT
      case 23: // MT
      case 24: // OR
      case 25: // AND
      case 26: // COMMENT
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
#line 27 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("Expression", "");
                          yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());
                          root = yylhs.value.as< Node * > ();
                          }
#line 648 "parser.tab.cc" // lalr1.cc:859
    break;

  case 3:
#line 32 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = yystack_[0].value.as< Node * > ();}
#line 654 "parser.tab.cc" // lalr1.cc:859
    break;

  case 4:
#line 33 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("AddExpression", "");
                                                 yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ());
                                                 yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());
                                                 }
#line 663 "parser.tab.cc" // lalr1.cc:859
    break;

  case 5:
#line 38 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("AddExpression", "");
                                                 yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ());
                                                 yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());
                                                 }
#line 672 "parser.tab.cc" // lalr1.cc:859
    break;

  case 6:
#line 43 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = yystack_[0].value.as< Node * > ();}
#line 678 "parser.tab.cc" // lalr1.cc:859
    break;

  case 7:
#line 44 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("MultExpression", "");
                                          yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ());
                                          yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());
                                          }
#line 687 "parser.tab.cc" // lalr1.cc:859
    break;

  case 8:
#line 49 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("multExpression", "");
                                          yylhs.value.as< Node * > ()->children.push_back(yystack_[2].value.as< Node * > ());
                                          yylhs.value.as< Node * > ()->children.push_back(yystack_[0].value.as< Node * > ());
                                          }
#line 696 "parser.tab.cc" // lalr1.cc:859
    break;

  case 9:
#line 54 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = new Node("NUM", yystack_[0].value.as< std::string > ());}
#line 702 "parser.tab.cc" // lalr1.cc:859
    break;

  case 10:
#line 55 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Node * > () = yystack_[1].value.as< Node * > ();}
#line 708 "parser.tab.cc" // lalr1.cc:859
    break;


#line 712 "parser.tab.cc" // lalr1.cc:859
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


  const signed char parser::yypact_ninf_ = -78;

  const signed char parser::yytable_ninf_ = -48;

  const short
  parser::yypact_[] =
  {
     -33,   -36,    33,     6,   -78,    16,   -78,   -36,    50,    15,
      21,   -78,    22,    -3,    26,    59,   -78,    36,   -36,   -78,
      34,    63,    -3,    42,    35,    71,   -78,   -36,   -78,   -78,
      38,    74,    72,    -3,    70,   -36,   -36,    67,    78,   -36,
      53,    80,     7,    56,    85,    87,    93,     7,    68,    -6,
      -3,    58,    58,    58,    76,    77,    58,    58,     7,    58,
      58,     0,   -78,   -78,   -78,   -78,   145,   -78,   -78,   -78,
     -78,   -78,   -78,    10,    -4,   -78,   -78,   161,   172,   -78,
     -78,   213,    90,    83,   183,   248,    96,   102,     7,    58,
      -5,    58,    58,    58,    58,    58,     3,     3,     3,     3,
      69,     7,    98,   -78,    58,     5,    58,   109,    91,   232,
     -78,   116,   248,   248,   248,   248,   248,    58,    -4,    -4,
     -78,   -78,   -78,   -78,    58,   114,   240,   -78,     7,   -78,
      58,   194,   122,    92,   -78,   -78,   205,   -78,   -78,   -78,
     -78
  };

  const unsigned char
  parser::yydefact_[] =
  {
       0,     0,     0,     0,    48,     0,     1,     0,     0,     0,
       0,     2,     0,     0,     0,     9,     8,     0,     0,    10,
       0,     0,     0,     0,     0,     0,     7,     0,     4,     5,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    25,    31,    30,    46,     0,    24,    22,    21,
      20,    19,    18,    17,    40,    43,    23,     0,     0,    11,
       3,     0,     0,     0,     0,    28,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    15,     0,    29,     0,     0,     0,     0,
      33,     0,    37,    38,    39,    35,    36,     0,    42,    41,
      44,    45,    14,    13,     0,     0,     0,    27,     0,    34,
       0,     0,     0,     0,    26,    12,     0,    47,    16,     6,
      32
  };

  const signed char
  parser::yypgoto_[] =
  {
     -78,   -78,   -78,   -78,    79,   -78,   -15,   -45,     2,   -78,
     -78,   -78,   -78,   -78,   -78,   -78,   -77,   -70,    -1
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,     2,     3,     8,    17,    23,    18,    48,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76
  };

  const unsigned char
  parser::yytable_[] =
  {
       5,    15,    54,    56,    86,     1,    10,    27,   117,     4,
      44,   110,    19,    83,    98,    99,    57,    24,    35,   118,
     119,    19,   -47,   -47,   -47,   -47,    31,    96,   120,   121,
      97,    16,    19,     6,    37,    38,    45,    46,    41,    47,
       4,    49,     4,   108,     7,     4,    49,    65,     9,    19,
      11,    12,     4,    13,    77,    78,   123,    49,    81,    82,
      87,    84,    85,    59,    14,    60,    61,    20,    21,    62,
      63,    64,    22,    26,    25,    28,    30,    32,    29,    33,
      36,    34,    39,   135,    40,    42,    43,    49,    50,   111,
      51,   109,    52,   112,   113,   114,   115,   116,    53,    89,
      49,    55,    65,     4,    90,   106,   125,   107,   126,    79,
      80,    91,   122,    92,    93,   127,    94,    95,   104,   131,
     124,   130,   128,    89,     0,   139,   132,    49,    90,    58,
       0,    89,   136,   103,     0,    91,    90,    92,    93,     0,
      94,    95,     0,    91,     0,    92,    93,     0,    94,    95,
       0,    88,     0,     0,    89,     0,     0,   133,     0,    90,
       0,     0,     0,     0,     0,   138,    91,   100,    92,    93,
      89,    94,    95,     0,     0,    90,     0,     0,   101,     0,
       0,    89,    91,     0,    92,    93,    90,    94,    95,   105,
       0,     0,    89,    91,     0,    92,    93,    90,    94,    95,
     137,     0,     0,    89,    91,     0,    92,    93,    90,    94,
      95,   140,     0,     0,    89,    91,     0,    92,    93,    90,
      94,    95,    89,   102,     0,     0,    91,    90,    92,    93,
       0,    94,    95,     0,    91,     0,    92,    93,     0,    94,
      95,    89,   129,     0,     0,     0,    90,     0,     0,    89,
     134,     0,     0,    91,    90,    92,    93,    89,    94,    95,
       0,    91,    90,    92,    93,     0,    94,    95,     0,    91,
       0,    92,    93,     0,    94,    95
  };

  const short
  parser::yycheck_[] =
  {
       1,     4,    47,     9,     4,    38,     7,    22,     5,    45,
       3,    16,    13,    58,    18,    19,    22,    18,    33,    96,
      97,    22,    17,    18,    19,    20,    27,    17,    98,    99,
      20,    34,    33,     0,    35,    36,    29,    30,    39,    32,
      45,    42,    45,    88,    38,    45,    47,    44,    32,    50,
       0,    36,    45,    32,    52,    53,   101,    58,    56,    57,
      61,    59,    60,     5,    42,     7,     8,    41,     9,    11,
      12,    13,    36,    10,    40,    33,     5,    39,    43,     5,
      10,     9,    15,   128,     6,    32,     6,    88,    32,    90,
       5,    89,     5,    91,    92,    93,    94,    95,     5,     9,
     101,    33,    44,    45,    14,     9,   104,     5,   106,    33,
      33,    21,    43,    23,    24,     6,    26,    27,    35,   117,
      22,     5,    31,     9,    -1,    33,   124,   128,    14,    50,
      -1,     9,   130,    43,    -1,    21,    14,    23,    24,    -1,
      26,    27,    -1,    21,    -1,    23,    24,    -1,    26,    27,
      -1,     6,    -1,    -1,     9,    -1,    -1,    43,    -1,    14,
      -1,    -1,    -1,    -1,    -1,    43,    21,     6,    23,    24,
       9,    26,    27,    -1,    -1,    14,    -1,    -1,     6,    -1,
      -1,     9,    21,    -1,    23,    24,    14,    26,    27,     6,
      -1,    -1,     9,    21,    -1,    23,    24,    14,    26,    27,
       6,    -1,    -1,     9,    21,    -1,    23,    24,    14,    26,
      27,     6,    -1,    -1,     9,    21,    -1,    23,    24,    14,
      26,    27,     9,    10,    -1,    -1,    21,    14,    23,    24,
      -1,    26,    27,    -1,    21,    -1,    23,    24,    -1,    26,
      27,     9,    10,    -1,    -1,    -1,    14,    -1,    -1,     9,
      10,    -1,    -1,    21,    14,    23,    24,     9,    26,    27,
      -1,    21,    14,    23,    24,    -1,    26,    27,    -1,    21,
      -1,    23,    24,    -1,    26,    27
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,    38,    47,    48,    45,    64,     0,    38,    49,    32,
      64,     0,    36,    32,    42,     4,    34,    50,    52,    64,
      41,     9,    36,    51,    64,    40,    10,    52,    33,    43,
       5,    64,    39,     5,     9,    52,    10,    64,    64,    15,
       6,    64,    32,     6,     3,    29,    30,    32,    53,    64,
      32,     5,     5,     5,    53,    33,     9,    22,    50,     5,
       7,     8,    11,    12,    13,    44,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    54,    54,    33,
      33,    54,    54,    53,    54,    54,     4,    64,     6,     9,
      14,    21,    23,    24,    26,    27,    17,    20,    18,    19,
       6,     6,    10,    43,    35,     6,     9,     5,    53,    54,
      16,    64,    54,    54,    54,    54,    54,     5,    62,    62,
      63,    63,    43,    53,    22,    54,    54,     6,    31,    10,
       5,    54,    54,    43,    10,    53,    54,     6,    43,    33,
       6
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    46,    47,    48,    49,    50,    51,    52,    52,    52,
      52,    53,    53,    53,    53,    53,    53,    54,    54,    54,
      54,    54,    54,    54,    54,    55,    55,    55,    55,    55,
      56,    56,    57,    58,    59,    60,    60,    60,    60,    60,
      61,    61,    61,    62,    62,    62,    63,    63,    64
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     3,    17,     6,     3,    16,     3,     1,     1,
       1,     3,     7,     5,     5,     4,     7,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     5,     4,     2,     3,
       1,     1,     6,     3,     4,     3,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     1,     3,     1
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
  "type", "statement", "expression", "otherExpression", "boolExpression",
  "funccallExpression", "lengthExpression", "indexExpression",
  "logExpression", "addExpression", "multExpression", "number",
  "identifier", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned char
  parser::yyrline_[] =
  {
       0,    27,    27,    33,    40,    47,    53,    65,    67,    69,
      71,    76,    81,    87,    92,    96,   101,   108,   112,   116,
     120,   124,   128,   132,   136,   141,   142,   145,   148,   151,
     155,   156,   158,   164,   169,   174,   178,   182,   186,   190,
     195,   196,   201,   206,   207,   212,   217,   218,   220
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
#line 1087 "parser.tab.cc" // lalr1.cc:1167
