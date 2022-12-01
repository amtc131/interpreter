package ast

import "github.com/amtc131/interpreter-go/token"

type Node interface {
	TokenLiteral() string // will be used only for debugging and testing
}

type Statement interface {
	Node
	statementNode() // help us by guiding the go compiler
}

type Expression interface {
	Node
	expressionNode() // help us by guiding the go compiler
}

type Program struct {
	Statements []Statement
}

type LetStatement struct {
	Token token.Token // the token.LEFT token
	Name  *Identifier
	Value Expression
}

func (p *Program) TokenLiteral() string {
	if len(p.Statements) > 0 {
		return p.Statements[0].TokenLiteral()
	} else {
		return ""
	}
}

type Identifier struct {
	Token token.Token //the token.IDENT token
	Value string
}

func (ls *LetStatement) statementNode() {}

func (ls *LetStatement) TokenLiteral() string {
	return ls.Token.Literal
}

func (i *Identifier) expressonNode() {}

func (i *Identifier) TokenLiteral() string { return i.Token.Literal }
