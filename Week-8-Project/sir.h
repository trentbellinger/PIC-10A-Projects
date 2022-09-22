#ifndef _SIR_
#define _SIR_

#include <cmath>

/**
@class SIR is a class to model a S-I-R spread of COVID-19
*/
class SIR {
private:
	double cm, cn; // daily number of contacts for morons and for normal people
	int P; // city population
	double f; // fraction of people in the city who are morons

	double istar; // fraction of people infected at time 0
	double beta; //probability of getting COVID in contact with an infected person
	double gamma, mu; // daily rate of recovery, mask risk reduction factor

	double t; // the elapsed time (days) since the start of the pandemic
	double N, M; // the number of normal people / morons

	double sn, sm; // fraction of susceptible normal people / morons
	double in, im; // fraction of infected normal people / morons
	double rn, rm; // fraction of removed normal people / morons
	
	/**
	* This function returns the value of psi.
	* @return psi which will be used in calculations
	*/
	double get_psi() const;

	/**
	* This function returns the value of (psi)m.
	* @return (psi)m which will be used in calculations
	*/
	double get_psim() const;

	/**
	* This function gives the value of (H)n
	* @param dT the time step in days
	* @return (H)n which will be used in calculations
	*/
	double get_Hn(const double dT) const;

	/**
	* This function gives the value of (H)m
	* @param dT the time step in days
	* @return (H)m which will be used in calculations
	*/
	double get_Hm(const double dT) const;

	/**
	* This functions gives the value of R.
	* @param dT the time step in days
	* @return (H)m which will be used in calculations
	*/
	double get_R(const double dT) const;

	/**
	* This function gives the the change of the fraction of susceptible
	  normal people over dT days.
	* @param dT the time step in days
	* @return delta sn
	*/
	double get_delta_sn(const double dT) const;

	/**
	* This function gives the change of the fraction of infected normal 
	  people over dT days.
	* @param dT the time step in days
	* @return delta in
	*/
	double get_delta_in(const double dT) const;
	
	/**
	* This function gives the change of the fraction of removed normal
	  people over dT days.
	* @param dT the time step in days
	* @return delta rn
	*/
	double get_delta_rn(const double dT) const;

	/**
	* This function gives the change of the fraction of susceptible morons
	  over dT days.
	* @param dT the time step in days
	* @return delta sm
	*/
	double get_delta_sm(const double dT) const;

	/**
	* This function gives the change of the fraction of infected morons
	  over dT days.
	* @param dT the time step in days
	* @return delta im
	*/
	double get_delta_im(const double dT) const;

	/**
	* This function gives the change of the fraction of removed morons over
	  dT days.
	* @param dT the time step in days
	* @return delta rm
	*/
	double get_delta_rm(const double dT) const;

public:
    /**
     * Constructor creates a S-I-R model given 8 inputted values.
     * @param _cm the daily number of contacts for morons
     * @param _cn the daily number of contacts for normal people
     * @param _P the total population of the city
     * @param _f the fraction of morons in the city
     * @param _istar the fraction of people who are infected at time 0
     * @param _beta the probability of being infected when in contact with an infected person
     * @param _gamma the daily rate of recovery for infected people
     * @param _mu the protection factor experienced by wearing a mask
     */
	SIR(double _cm, double _cn, int _P, double _f, double _istar, double _beta,
		double _gamma, double _mu);

	/**
	* This function advances the simulation forward by dT days, changing the
	  member variables accordingly.
	* @param dT the time step in days
	*/
	void step(const double dT);

	/**
	* This function allows the user to access the number of days since the
	  pandemic started.
	* @return the time in days since the pandemic started
	*/
	double get_time() const;

	/**
	* This function allows the user to access the current fraction of normal
	  people who are susceptible.
	* @return sn at the current time t
	*/
	double get_sn() const;

	/**
	* This function allows the user to access the current fraction of normal
	  people who are infected.
	* @return in at the durrent time t
	*/
	double get_in() const;

	/**
	* This function allows the user to access the current fraction of normal
	  people who are removed.
	* @return rn at the current time t
	*/
	double get_rn() const;

	/**
	* This function allows the user to access the current fraction of morons
	  who are susceptible.
	* @return sm at the current time t
	*/
	double get_sm() const;

	/**
	* This function allows the user to access the current fraction of morons
	  who are infected.
	* @return im at the current time t
	*/
	double get_im() const;

	/**
	* This function allows the user to access the current fraction of morons
	  who are removed.
	* @return rm at the current time t
	*/
	double get_rm() const;

};

#endif
