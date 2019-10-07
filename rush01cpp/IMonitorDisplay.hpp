/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaydont <chaydont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 11:36:39 by chaydont          #+#    #+#             */
/*   Updated: 2019/06/01 17:16:46 by chaydont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORDISPLAY_HPP
#define IMONITORDISPLAY_HPP

#include "IMonitorModule.hpp"

class IMonitorDisplay {
    public:
        virtual void display() const = 0;
};

#endif /* IMONITORDISPLAY_HPP */
