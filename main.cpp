#include "main.h"

tictactoe::tictactoe() {
	
	for ( int i = 0; i < 9; i++ ) {
		buttonHolder.push_back( new Gtk::Button() );
	}

	for ( int i = 0; i < 3; i++ ) {
		boxes.push_back( new Gtk::HBox() );
	}

	for ( int i = 0; i < 3;  i++ ) {
		for ( int x = 0; x < 3; x++ ) {
			int id = i*3 + x;
			boxes[i]->add( *buttonHolder[id] );
			buttonHolder[id]->set_size_request( 100, 40 );
			buttonHolder[id]->show();
		}
		boxes[i]->show();
		vertical.add( *boxes[i] );
	}

				
	this->turn = 0;
	this->numOff = 0;
	this->winner = 0;

	this->add( vertical );

	label.set_label("X's turn");
	vertical.add(label);
	label.show();
	vertical.show();
}

tictactoe::~tictactoe() {
}

int main(int argc, char* argv[]) {
	Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv, "Tic.Toc.Toe");
	tictactoe a;
	return app->run(a);
}
