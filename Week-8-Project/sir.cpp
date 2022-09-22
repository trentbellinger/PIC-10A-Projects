#include "sir.h"

// returns the value of psi
double SIR::get_psi() const {
	return N * cn + M * cm;
}

// returns the value of psim
double SIR::get_psim() const {
	return M * cm / get_psi();
}

// returns the value of (H)n
double SIR::get_Hn(const double dT) const {
	return 1 - exp(-beta * dT * cn * ((mu * (1 - get_psim()) * in) / (1 - f) +
		(get_psim() * im / f)));
}

// returns the value of (H)m
double SIR::get_Hm(const double dT) const {
	return 1 - exp(-beta * dT * cm * ((mu * (1 - get_psim()) * in) / (1 - f) +
		(get_psim() * im / f)));
}

// returns the value of R
double SIR::get_R(const double dT) const {
	return 1 - exp(-gamma * dT);
}

// returns the change in the fraction of normal people who are susceptible (delta sn)
double SIR::get_delta_sn(const double dT) const {
	return -get_Hn(dT) * sn;
}

// returns the change in the fraction of normal people who are infected (delta in)
double SIR::get_delta_in(const double dT) const {
	return get_Hn(dT) * sn - get_R(dT) * in;
}

// returns the change in the fraction of normal people who are removed (delta rn)
double SIR::get_delta_rn(const double dT) const {
	return get_R(dT) * in;
}

// returns the change in the fraction of morons who are susceptible (delta sm)
double SIR::get_delta_sm(const double dT) const {
	return -get_Hm(dT) * sm;
}

// returns the change in the fraction of morons who are infected (delta im)
double SIR::get_delta_im(const double dT) const {
	return get_Hm(dT) * sm - get_R(dT) * im;
}

// returns the change in the fraction of morons who are removed (delta rm)
double SIR::get_delta_rm(const double dT) const {
	return get_R(dT) * im;
}

// constructor for the SIR class with all member variables initialized
SIR::SIR(double _cm, double _cn, int _P, double _f, double _istar, double _beta,
	double _gamma, double _mu) : cm(_cm), cn(_cn), P(_P), f(_f), istar(_istar),
	beta(_beta), gamma(_gamma), mu(_mu), t(0), N((1 - f)* P), M(f* P),
	sn((1 - istar)* (1 - f)), in(istar* (1 - f)), rn(0),
	sm((1 - istar)* f), im(istar* f), rm(0) {}

// advances the simulation forward one day, changing member variables accordingly
void SIR::step(const double dT) {
	const double delta_sn = get_delta_sn(dT); // get variable for delta sn
	const double delta_in = get_delta_in(dT); // get varible for delta in
	const double delta_rn = get_delta_rn(dT); // get variable for delta rn

	const double delta_sm = get_delta_sm(dT); // get variable for delta sm
	const double delta_im = get_delta_im(dT); // get variable for delta im
	const double delta_rm = get_delta_rm(dT); // get variable for delta rm

	sn += delta_sn; // change sm to be increased by delta sm
	in += delta_in; // change in to be increased by delta in
	rn += delta_rn; // change rn to be increased by delta rn

	sm += delta_sm; // change sm to be increased by delta sm
	im += delta_im; // change im to be increased by delta im
	rm += delta_rm; // change rm to be increased by delta rm

	t += dT; // change t to be increased by dT
}

// returns the current time in days since the start of the pandemic
double SIR::get_time() const { return t; };

// returns the current fraction of normal people who are susceptible
double SIR::get_sn() const { return sn; }

// returns the current fraction of normal people who are infected
double SIR::get_in() const { return in; }

// returns the current fraction of normal people who are removed
double SIR::get_rn() const { return rn; }

// returns the current fraction of morons who are susceptible
double SIR::get_sm() const { return sm; }

// returns the current fraction of morons who are infected
double SIR::get_im() const { return im; }

// returns the current fraction of morons who are removed
double SIR::get_rm() const { return rm; }
