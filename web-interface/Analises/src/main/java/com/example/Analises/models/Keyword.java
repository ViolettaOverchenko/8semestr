package com.example.Analises.models;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;

@Entity
public class Keyword {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY )
    private Long idKeyword;
    private String descriptionKeyword;
    private  int periodicityKeyword;

    public Long getIdKeyword() {
        return idKeyword;
    }

    public void setIdKeyword(Long idKeyword) {
        this.idKeyword = idKeyword;
    }

    public String getDescriptionKeyword() {
        return descriptionKeyword;
    }

    public void setDescriptionKeyword(String descriptionKeyword) {
        this.descriptionKeyword = descriptionKeyword;
    }

    public int getPeriodicityKeyword() {
        return periodicityKeyword;
    }

    public void setPeriodicityKeyword(int periodicityKeyword) {
        this.periodicityKeyword = periodicityKeyword;
    }

    public Keyword() {
    }

    public Keyword(String descriptionKeyword) {
        this.descriptionKeyword = descriptionKeyword;
    }
}
