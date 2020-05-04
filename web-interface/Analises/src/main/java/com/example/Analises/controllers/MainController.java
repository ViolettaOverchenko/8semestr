package com.example.Analises.controllers;

import com.example.Analises.models.Keyword;
import com.example.Analises.repository.KeywordRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestParam;

import java.util.ArrayList;
import java.util.Optional;

@Controller
public class MainController {

    @Autowired
    private KeywordRepository keywordRepository;

    @GetMapping("/")
    public String home( Model model) {
        Iterable<Keyword> keywords = keywordRepository.findAll();
        model.addAttribute("keywords", keywords);
        return "home";
    }

    @PostMapping("/")
    private String keywordAdd(@RequestParam String descriptionKeyword, Model model){
        Keyword keyword = new Keyword(descriptionKeyword);
        keywordRepository.save(keyword);
        return "redirect:/";
    }

    @GetMapping("/edit/{id}")
    public String keywordEdit(@PathVariable(value = "id") long id, Model model) {
        if(!keywordRepository.existsById(id)) {
            return "redirect:/";
        }
        Optional<Keyword> keywords = keywordRepository.findById(id);
        ArrayList<Keyword> res = new ArrayList<>();
        keywords.ifPresent(res::add);
        model.addAttribute("keywords", res);
        return "keywordEdit";
    }

    @PostMapping("/edit/{id}")
    private String keywordUpdate(@PathVariable(value = "id") long id, @RequestParam String descriptionKeyword, Model model){
        Keyword keyword = keywordRepository.findById(id).orElseThrow(IllegalStateException::new);
        keyword.setDescriptionKeyword(descriptionKeyword);
        keywordRepository.save(keyword);
        return "redirect:/";
    }

    @PostMapping("/delete/{id}")
    private String keywordDelete(@PathVariable(value = "id") long id, Model model){
        Keyword keyword = keywordRepository.findById(id).orElseThrow(IllegalStateException::new);
        keywordRepository.delete(keyword);
        return "redirect:/";
    }
}